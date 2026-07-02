#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool divisibleByK(vector<int>& arr, int k) {
        int n = arr.size();

        if (n > k)
            return true;

        vector<bool> dp(k, false);

        for (int i = 0; i < n; i++) {
            if (dp[0])
                return true;

            vector<bool> temp(k, false);

            for (int j = 0; j < k; j++) {
                if (dp[j] && !dp[(j + arr[i]) % k])
                    temp[(j + arr[i]) % k] = true;
            }

            // Update dp with new remainders
            for (int j = 0; j < k; j++)
                if (temp[j])
                    dp[j] = true;

            // Single element subset
            dp[arr[i] % k] = true;
        }

        return dp[0];
    }

};
