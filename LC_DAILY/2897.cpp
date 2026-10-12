#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int setBitCnt[30] = { 0 };

        for (int n : nums) {
            for (int i = 0; i < 30; i++) {
                if (n & (1 << i)) {
                    setBitCnt[i]++;
                }
            }
        }

        long long res = 0;
        for (int i = 0; i < k; i++) {
            long long curr = 0;
            for (int j = 29; j >= 0; j--) {
                if (setBitCnt[j] > 0) {
                    curr |= (1LL << j);
                    setBitCnt[j]--;
                }
            }
            res = (res + curr * curr) % MOD;
        }

        return (int)res;
    }
};