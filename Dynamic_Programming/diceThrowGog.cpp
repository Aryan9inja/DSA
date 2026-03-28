#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int recursive(int dice, int faces, int target){
        if(target<0) return 0;
        
        if(dice==0 && target!=0){
            return 0;
        }
        
        if(dice!=0 && target==0){
            return 0;
        }
        
        if(dice==0  && target==0){
            return 1;
        }
        
        int ans=0;
        for(int i=1; i<=faces; i++){
            ans=ans+recursive(dice-1, faces, target-i);
        }
        
        return ans;
    }
    
    int memoization(int dice, int faces, int target, vector<vector<int>>& dp){
        if(target<0) return 0;
        
        if(dice==0 && target!=0){
            return 0;
        }
        
        if(dice!=0 && target==0){
            return 0;
        }
        
        if(dice==0  && target==0){
            return 1;
        }
        
        if(dp[dice][target]!=-1)
            return dp[dice][target];
        
        int ans=0;
        for(int i=1; i<=faces; i++){
            ans=ans+memoization(dice-1, faces, target-i, dp);
        }
        
        return dp[dice][target] = ans;
    }
    
    int tabulation(int d, int f, int t){
        vector<vector<int>> dp(d+1, vector<int>(t+1, 0));
        
        dp[0][0]=1;
        
        for(int dice=1; dice<=d; dice++){
            for(int target=1; target<=t; target++){
                int ans=0;
                for(int i=1; i<=f; i++){
                    if(target-i >= 0)
                        ans=ans+dp[dice-1][target-i];
                }
                dp[dice][target] = ans;
            }
        }
        
        return dp[d][t];
    }
    
    int spaceOptimize(int d, int f, int t){
        vector<int> prev(t+1, 0);
        vector<int> curr(t+1, 0);
        
        prev[0]=1;
        
        for(int dice=1; dice<=d; dice++){
            for(int target=1; target<=t; target++){
                int ans=0;
                for(int i=1; i<=f; i++){
                    if(target-i >= 0)
                        ans=ans+prev[target-i];
                }
                curr[target] = ans;
            }
            prev=curr;
        }
        
        return prev[t];
    }
    
public:
    int noOfWays(int m, int n, int x) {
        // return recursive(n, m, x);
        
        // vector<vector<int>> dp(n+1, vector<int>(x+1, -1));
        // return memoization(n, m, x, dp);
        
        // return tabulation(n, m, x);
        
        return spaceOptimize(n, m, x);
    }
};