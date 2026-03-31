#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int recursive(int idx, int diff, vector<int>& arr){
        if(idx < 0) return 0;
        
        int ans = 0;
        for(int j = idx-1; j>=0; j--){
            if(arr[idx] - arr[j] == diff){
                ans = max(ans, 1 + recursive(j, diff, arr));
            }
        }
        return ans;
    }
    
    int memoized(int idx, int diff, vector<int>& arr, 
    unordered_map<int, int> dp[]){
        if(idx < 0) return 0;
        
        if(dp[idx].count(diff)){
            return dp[idx][diff];
        }
        
        int ans = 0;
        for(int j = idx-1; j>=0; j--){
            if(arr[idx] - arr[j] == diff){
                ans = max(ans, 1 + memoized(j, diff, arr, dp));
            }
        }
        return dp[idx][diff]=ans;
    }
    
    int tabulation(vector<int>& arr){
        int n = arr.size();
        unordered_map<int, int> dp[n+1];
        
        int ans = 0;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                int diff = arr[i] - arr[j];
                int cnt = 1;
                
                if(dp[j].count(diff)){
                    cnt = dp[j][diff];
                }
                
                dp[i][diff] = 1 + cnt;
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
    
public:
    int lengthOfLongestAP(vector<int>& arr) {
        int n = arr.size();
        if(n <= 2) return n;
        
        // unordered_map<int, int> dp[n+1];
        // int ans = 0;
        // for(int i = 0; i < n; i++){
        //     for(int j = i+1; j < n; j++){
        //         // 2 because of i & j already in AP
        //         // ans = max(ans, 2 + recursive(i, arr[j]-arr[i], arr));
        //         ans = max(ans, 2 + memoized(i, arr[j]-arr[i], arr, dp));
        //     }
        // }
        
        int ans = tabulation(arr);
        return ans;
    }
};