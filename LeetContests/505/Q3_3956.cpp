#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n = nums.size();
        vector<ll> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        const long long INF = 1e18;

        vector<vector<ll>> dp(m + 1, vector<ll>(n + 1, -INF));
        for(int i=0; i<=n; i++){
            dp[0][i] = 0;
        }

        ll maxSum = -INF;

        for(int j=1; j<=m; j++){
            deque<int> dq;

            for(int i=1; i<=n; i++){
                dp[j][i]=dp[j][i-1];

                int newK = i-l;

                if(newK >=0 && dp[j-1][newK] != -INF){
                    ll newVal = dp[j-1][newK] - pref[newK];

                    while(!dq.empty()){
                        int back_k = dq.back();
                        long long back = dp[j-1][back_k] - pref[back_k];

                        if(back <= newVal){
                            dq.pop_back();
                        }else{
                            break;
                        }
                    }

                    dq.push_back(newK);
                }

                while(!dq.empty() && dq.front() < i-r){
                    dq.pop_front();
                }

                if(!dq.empty()){
                    int bestK = dq.front();
                    ll best = dp[j-1][bestK] - pref[bestK];
                    dp[j][i] = max(dp[j][i], pref[i]+best);
                }
            }

            maxSum = max(maxSum, dp[j][n]);
        }

        return maxSum;
    }
};