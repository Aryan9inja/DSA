#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> cnt(k, 0);

        cnt[0] = 1;

        int prefix = 0;
        int res = 0;

        for (const int& n : nums) {
            prefix += n;

            int rem = ((prefix % k) + k) % k;

            res += cnt[rem];

            cnt[rem]++;
        }

        return res;
    }
};