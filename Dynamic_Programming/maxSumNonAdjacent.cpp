#include <bits/stdc++.h> 
using namespace std;

// R -> L
int recursively(vector<int> &nums, int n){
    if(n<0) return 0;
    if(n==0) return nums[0];

    int incl=recursively(nums, n-2) + nums[n];
    int excl=recursively(nums, n-1) + 0;

    return max(incl, excl);
}

int memoization(vector<int> &nums, int n, vector<int> &dp){
    if(n<0) return 0;
    if(n==0) return nums[0];

    if(dp[n]!=-1) return dp[n];

    int incl=memoization(nums, n-2,dp) + nums[n];
    int excl=memoization(nums, n-1,dp) + 0;

    dp[n]= max(incl, excl);
    return dp[n];
}

int tabulation(vector<int> &nums, int n){
    vector<int> dp(n+1,0);

    dp[0]=nums[0];

    for(int i=1;i<=n;i++){
        int incl = nums[i]; 
        if(i - 2 >= 0) incl += dp[i-2];
        int excl=dp[i-1]+0;

        dp[i]=max(incl,excl);
    }
    return dp[n];
}

int spaceOptimization(vector<int> &nums, int n){
    int prev2=0;
    int prev1=nums[0];

    for(int i=1;i<=n;i++){
        int incl = prev2+nums[i];
        int excl= prev1+0;

        int ans=max(incl,excl);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    // vector<int> dp(n,-1);
    // int ans=recursively(nums, n-1);
    // int ans=memoization(nums, n-1, dp);
    // int ans=tabulation(nums, n-1);
    int ans=spaceOptimization(nums, n-1);
    return ans;
}