#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int recursive(vector<int>& satisfaction, int index, int time){
        if(index==satisfaction.size()){
            return 0;
        }

        int include = (satisfaction[index] * (time+1)) + recursive(satisfaction, index+1, time+1);
        int exclude = 0 + recursive(satisfaction, index+1, time);

        return max(include, exclude);
    }

    int memoization(vector<int>& satisfaction, int index, int time, vector<vector<int>>& dp){
        if(index==satisfaction.size()){
            return 0;
        }

        if(dp[index][time]!=-1) return dp[index][time];

        int include = (satisfaction[index] * (time+1)) + memoization(satisfaction, index+1,
        time+1, dp);
        int exclude = 0 + memoization(satisfaction, index+1, time, dp);

        return dp[index][time] = max(include, exclude);
    }

    int tabulation(vector<int>& satisfaction){
        int n = satisfaction.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int index = n-1; index>=0; index--){
            for(int time = index; time>=0; time--){
                int include = (satisfaction[index] * (time+1)) + dp[index+1][time+1];
                int exclude = 0 + dp[index+1][time];

                dp[index][time] = max(include, exclude);
            }
        }
        return dp[0][0];
    }

    int spaceOptimal(vector<int>& satisfaction){
        int n = satisfaction.size();
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);

        for(int index = n-1; index>=0; index--){
            for(int time = index; time>=0; time--){
                int include = (satisfaction[index] * (time+1)) + next[time+1];
                int exclude = 0 + next[time];

                curr[time] = max(include, exclude);
            }
            next = curr;
        }
        return next[0];
    }

public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());

        // return recursive(satisfaction, 0, 0);

        // int n = satisfaction.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return memoization(satisfaction, 0, 0, dp);

        // return tabulation(satisfaction);

        return spaceOptimal(satisfaction);
    }
};