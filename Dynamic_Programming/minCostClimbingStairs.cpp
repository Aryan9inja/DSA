#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int recursiveOnly(vector<int>& cost, int n){
        if(n==0) return cost[0];
        if(n==1) return cost[1];

        int ans=cost[n]+min(recursiveOnly(cost,n-1),recursiveOnly(cost,n-2));
        return ans;
    }

    int memoization(vector<int>& cost, int n, vector<int> dp){
        if(n==0) return cost[0];
        if(n==1) return cost[1];

        if(dp[n]!=-1) return dp[n];

        dp[n]=cost[n]+min(memoization(cost,n-1,dp),memoization(cost,n-2,dp));
        return dp[n];
    }

    int tabulation(vector<int>& cost, int n){
        vector<int> dp(n+1);
        if(n==0) return cost[0];
        if(n==1) return cost[1];

        dp[0]=cost[0];
        dp[1]=cost[1];

        for(int i=2;i<=n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return dp[n];
    }

    int spaceOptimization(vector<int>& cost, int n){
        if(n==0) return cost[0];
        if(n==1) return cost[1];

        int prev2=cost[0];
        int prev1=cost[1];

        for(int i=2;i<=n;i++){
            int curr=cost[i]+min(prev2,prev1);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        // vector<int> dp(n+1,-1);
        // int ans=min(recursiveOnly(cost,n-1), recursiveOnly(cost,n-2));
        // int ans=min(memoization(cost,n-1,dp),memoization(cost,n-2,dp));
        // int ans=min(tabulation(cost,n-1),tabulation(cost,n-2));
        int ans=min(spaceOptimization(cost,n-1),spaceOptimization(cost,n-2));
        return ans;
    }
};