#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int recursive(vector<int>& obstacles, int currlane, int currpos, int n){
        if(currpos==n-1) return 0;

        if(obstacles[currpos+1]!=currlane){
            return recursive(obstacles, currlane, currpos+1, n);
        }
        else{
            // sideways jump;
            int ans=INT_MAX; // to get the route with min jumps
            for(int i=1;i<=3;i++){
                // don't jump on own lane or an obstacle
                if(currlane!=i && obstacles[currpos]!=i){
                    ans=min(ans, 1+recursive(obstacles, i, currpos, n));
                }
            }
            return ans;
        }
    }

    int memoization(vector<int>& obstacles, int currlane, int currpos, int n,
    vector<vector<int>>& dp){
        if(currpos==n-1) return 0;

        if(dp[currlane][currpos]!=-1) return dp[currlane][currpos];

        if(obstacles[currpos+1]!=currlane){
            return memoization(obstacles, currlane, currpos+1, n, dp);
        }
        else{
            // sideways jump;
            int ans=INT_MAX; // to get the route with min jumps
            for(int i=1;i<=3;i++){
                // don't jump on own lane or an obstacle
                if(currlane!=i && obstacles[currpos]!=i){
                    ans=min(ans, 1+memoization(obstacles, i, currpos, n, dp));
                }
            }
            dp[currlane][currpos]=ans;
            return dp[currlane][currpos];
        }
    }

    int tabulation(vector<int>& obstacles){
        int n = obstacles.size()-1;
        vector<vector<int>> dp(4, vector<int>(n+1, 1e9));

        dp[0][n]=0;
        dp[1][n]=0;
        dp[2][n]=0;
        dp[3][n]=0;

        for(int currpos=n-1;currpos>=0;currpos--){
            for(int currlane=1;currlane<=3;currlane++){
                if(obstacles[currpos+1]!=currlane){
                    dp[currlane][currpos]=dp[currlane][currpos+1];
                }
                else{
                    // sideways jump;
                    int ans=1e9; // to get the route with min jumps
                    for(int i=1;i<=3;i++){
                        // don't jump on own lane or an obstacle
                        if(currlane!=i && obstacles[currpos]!=i){
                            ans=min(ans, 1+dp[i][currpos+1]);
                        }
                    }
                    dp[currlane][currpos] = ans;
                }
            }
        }

        return min(dp[2][0], min(1+dp[1][0], 1+dp[3][0]));
    }

    int spaceOptimal(vector<int>& obstacles){
        int n = obstacles.size()-1;
        vector<int> curr(4);
        vector<int> next(4, 0);

        for(int currpos=n-1;currpos>=0;currpos--){
            for(int currlane=1;currlane<=3;currlane++){
                if(obstacles[currpos+1]!=currlane){
                    curr[currlane]=next[currlane];
                }
                else{
                    // sideways jump;
                    int ans=1e9; // to get the route with min jumps
                    for(int i=1;i<=3;i++){
                        // don't jump on own lane or an obstacle
                        if(currlane!=i && obstacles[currpos]!=i){
                            ans=min(ans, 1+next[i]);
                        }
                    }
                    curr[currlane] = ans;
                }
            }
            next=curr;
        }

        return min(next[2], min(1+next[1], 1+next[3]));
    }

public:
    int minSideJumps(vector<int>& obstacles) {
        // int n=obstacles.size();
        // return recursive(obstacles, 2, 0, n);

        // int n=obstacles.size();
        // vector<vector<int>> dp(4, vector<int>(n,-1));
        // return memoization(obstacles, 2, 0, n, dp);

        // return tabulation(obstacles);

        return spaceOptimal(obstacles);
    }
};