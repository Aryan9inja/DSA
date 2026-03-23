#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int recursive(vector<vector<int>>& mat, int i, int j, int& maxi){
        if(i>=mat.size() || j>=mat[0].size()){
            return 0;
        }
        
        int right = recursive(mat, i, j+1, maxi);
        int diagonal = recursive(mat, i+1, j+1, maxi);
        int down = recursive(mat, i+1, j, maxi);
        
        if(mat[i][j]==1){
            int ans = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, ans);
            return ans;
        }else{
            return 0;
        }
    }
    
    int memoization(vector<vector<int>>& mat, int i, int j, int& maxi, vector<vector<int>>& dp){
        if(i>=mat.size() || j>=mat[0].size()){
            return 0;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int right = memoization(mat, i, j+1, maxi, dp);
        int diagonal = memoization(mat, i+1, j+1, maxi, dp);
        int down = memoization(mat, i+1, j, maxi, dp);
        
        if(mat[i][j]==1){
            dp[i][j] = 1 + min(right, min(diagonal, down));
            maxi=max(maxi, dp[i][j]);
            return dp[i][j];
        }else{
            return dp[i][j] = 0;
        }
    }
    
    int tabulation(vector<vector<int>>& mat, int& maxi){
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down = dp[i+1][j];
                
                if(mat[i][j]==1){
                    dp[i][j] = 1 + min(right, min(diagonal, down));
                    maxi=max(maxi, dp[i][j]);
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        return dp[0][0];
    }
    
    int spaceOpt1(vector<vector<int>>& mat, int& maxi){
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> curr(m+1, 0); // dp[i]
        vector<int> next(m+1, 0); // dp[i+1]
        
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int right = curr[j+1];
                int diagonal = next[j+1];
                int down = next[j];
                
                if(mat[i][j]==1){
                    curr[j] = 1 + min(right, min(diagonal, down));
                    maxi=max(maxi, curr[j]);
                }else{
                    curr[j] = 0;
                }
            }
            next=curr;
        }
        return next[0];
    }
    
    int spaceOpt2(vector<vector<int>>& mat, int& maxi){
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> dp(m+1, 0); // single array, starts as "next" row (all zeros)
        
        for(int i=n-1; i>=0; i--){
            int prev = 0;  // saves dp[j+1] BEFORE we overwrite dp[j]
                           // = the diagonal value for next j iteration
            for(int j=m-1; j>=0; j--){
                int temp = dp[j];  // save dp[j] = down (will be diagonal for j-1)
                
                int right    = dp[j+1]; // already updated this row
                int diagonal = prev;    // dp[j+1] from BEFORE this row's update
                int down     = dp[j];   // dp[j] from previous row (not yet overwritten)
                
                if(mat[i][j] == 1){
                    dp[j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, dp[j]);
                } else {
                    dp[j] = 0;
                }
                
                prev = temp;
            }
        }
        return dp[0];
    }
public:
    int maxSquare(vector<vector<int>>& mat) {
        // int maxi = 0;
        // return recursive(mat, 0, 0, maxi);
        
        // int maxi = 0;
        // int n = mat.size();
        // int m = mat[0].size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // memoization(mat, 0, 0, maxi, dp);
        // return maxi;
        
        // int maxi=0;
        // tabulation(mat, maxi);
        // return maxi;
        
        // int maxi=0;
        // spaceOpt1(mat, maxi);
        // return maxi;
        
        int maxi=0;
        spaceOpt2(mat, maxi);
        return maxi;
    }
};