#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool recursive(int idx, int target, vector<int>& arr){
        if(idx >= arr.size()) return 0;
            
        if(target < 0) return 0;
        
        if(target == 0) return 1;
        
        bool include = recursive(idx+1, target-arr[idx], arr);
        bool exclude = recursive(idx+1, target-0, arr);
        
        return include or exclude;
    }
    
    bool memoization(int idx, int target, vector<int>& arr, 
    vector<vector<int>>& dp){
        if(idx >= arr.size()) return 0;
            
        if(target < 0) return 0;
        
        if(target == 0) return 1;
        
        if(dp[idx][target]!=-1) return dp[idx][target];
        
        bool include = memoization(idx+1, target-arr[idx], arr, dp);
        bool exclude = memoization(idx+1, target-0, arr, dp);
        
        dp[idx][target]=include or exclude;
        
        return dp[idx][target];
    }
    
    bool tabulation(vector<int>& arr, int total){
        int n = arr.size();
        vector<vector<bool>> dp(n+1, vector<bool>(total+1, false));
        
        for(int i=0; i<=n; i++){
            dp[i][0]=true;
        }
        
        for(int idx=n-1; idx>=0; idx--){
            for(int target=0; target<=total/2; target++){
                bool include = 0;
                if(target-arr[idx]>=0)
                    include = dp[idx+1][target-arr[idx]];
                bool exclude = dp[idx+1][target-0];
                
                dp[idx][target]=include or exclude;
            }
        }
        return dp[0][total/2];
    }
    
    bool spaceOptimal(vector<int>& arr, int total){
        int n = arr.size();
        vector<bool> curr(total+1, false);
        vector<bool> next(total+1, false);
        
        curr[0]=true;
        next[0]=true;
        
        for(int idx=n-1; idx>=0; idx--){
            for(int target=0; target<=total/2; target++){
                bool include = 0;
                if(target-arr[idx]>=0)
                    include = next[target-arr[idx]];
                bool exclude = next[target-0];
                
                curr[target]=include or exclude;
            }
            next=curr;
        }
        return curr[total/2];
    }

public:
    bool equalPartition(vector<int>& arr) {
        int total = 0;
        for(int i: arr) total+=i;
        
        // If total is odd, return 0
        if(total & 1) return 0;
        
        // int target = total/2;
        
        // return recursive(0, target, arr);
        
        // int n = arr.size();
        // vector<vector<int>> dp(n, vector<int>(target+1, -1));
        // return memoization(0, target, arr, dp);
        
        return tabulation(arr, total);
    }
};