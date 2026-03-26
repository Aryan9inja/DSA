#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int recursive(vector<int>& arr, int curr, int prev){
        if(curr == arr.size()){
            return 0;
        }
        
        int include = 0;
        if(prev == -1 || arr[curr]>arr[prev]){
            include = 1 + recursive(arr, curr+1, curr);
        }
        
        int exclude = 0 + recursive(arr, curr+1, prev);
        
        return max(include, exclude);
    }
    
    int memoization(vector<int>& arr, int curr, int prev, vector<vector<int>>& dp){
        if(curr == arr.size()){
            return 0;
        }
        
        // to mitigate invalid index
        if(dp[curr][prev+1] != -1)
            return dp[curr][prev+1];
        
        int include = 0;
        if(prev == -1 || arr[curr]>arr[prev]){
            include = 1 + memoization(arr, curr+1, curr, dp);
        }
        
        int exclude = 0 + memoization(arr, curr+1, prev, dp);
        
        // to mitigate invalid index
        return dp[curr][prev+1]=max(include, exclude);
    }
    
    int tabulation(vector<int>& arr){
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int curr=n-1; curr>=0; curr--){
            for(int prev=curr-1; prev>=-1; prev--){
                int include = 0;
                if(prev == -1 || arr[curr]>arr[prev]){
                    include = 1 + dp[curr+1][curr+1];
                }
                
                int exclude = 0 + dp[curr+1][prev+1];
                
                // to mitigate invalid index
                dp[curr][prev+1]=max(include, exclude);
            }
        }
        return dp[0][0];
    }
    
    int spaceOptimal(vector<int>& arr){
        int n = arr.size();
        vector<int> currRow(n+1,0);
        vector<int> nextRow(n+1,0);
        
        for(int curr=n-1; curr>=0; curr--){
            for(int prev=curr-1; prev>=-1; prev--){
                int include = 0;
                if(prev == -1 || arr[curr]>arr[prev]){
                    include = 1 + nextRow[curr+1];
                }
                
                int exclude = 0 + nextRow[prev+1];
                
                // to mitigate invalid index
                currRow[prev+1]=max(include, exclude);
            }
            nextRow=currRow;
        }
        return nextRow[0];
    }
    
    int solveOptimal(vector<int>& arr){
        int n = arr.size();
        
        if(n==0) return 0;
        
        vector<int> ans;
        ans.push_back(arr[0]);
        
        for(int i=1; i<n; i++){
            if(arr[i]>ans.back()){
                ans.push_back(arr[i]);
            }
            else{
                // Find where we can insert current element
                // Just badaa element than this one
                int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
                ans[index]=arr[i];
            }
        }
        return ans.size();
    }
    
public:
    int lis(vector<int>& arr) {
        // return recursive(arr, 0, -1);
        
        // int n = arr.size();
        // vector<vector<int>> dp(n, vector<int>(n+1,-1));
        // return memoization(arr, 0, -1, dp);
        
        // return tabulation(arr);
        
        // return spaceOptimal(arr);
        
        return solveOptimal(arr);
    }
};