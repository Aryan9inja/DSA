#include <bits/stdc++.h>
using namespace std;

int recursively(vector<int> &num, int x){
    if(x==0) return 0;
    if(x<0) return INT_MAX;

    int mini=INT_MAX;

    for(int i=0;i<num.size();i++){
        int ans=recursively(num, x-num[i]);
        if(ans!=INT_MAX){
            // +1 for the newly added coin
            mini=min(mini,ans+1);
        }
    }
    return mini;
}

int memoization(vector<int> &num, int x, vector<int> &dp){
    if(x==0) return 0;
    if(x<0) return INT_MAX;

    int mini=INT_MAX;

    if(dp[x]!=-1) return dp[x];

    for(int i=0;i<num.size();i++){
        int ans=memoization(num, x-num[i],dp);
        if(ans!=INT_MAX){
            // +1 for the newly added coin
            mini=min(mini,ans+1);
        }
    }
    dp[x]=mini;
    return mini;
}

int tabulation(vector<int> &num, int x){
    vector<int> dp(x+1, INT_MAX);
    dp[0]=0;

    for(int i=1;i<=x;i++){
        // check for each coin
        for(int j=0;j<num.size();j++){
            if(i-num[j]>=0 && dp[i-num[j]]!=INT_MAX){
                dp[i]=min(dp[i],1+dp[i-num[j]]);
            }
        }
    }

    return dp[x];
}

int minimumElements(vector<int> &num, int x)
{
    // vector<int> dp(x+1,-1);
    // int ans=recursively(num, x);
    // int ans=memoization(num,x,dp);
    int ans=tabulation(num,x);
    // space optimization not possible
    if(ans==INT_MAX) return -1;
    return ans;
}