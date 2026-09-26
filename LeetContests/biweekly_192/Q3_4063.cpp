#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        auto mod = [k](long long val) -> int {
            long long rem = val % k;
            return rem < 0 ? rem + k : rem;
            };

        for (int i = 0; i < n; i++) {
            long long subSum = 0;
            unordered_set<int> twoX;

            for (int j = i; j < n; j++) {
                subSum += nums[j];

                twoX.insert(mod(2LL * nums[j]));

                int remainder = mod(subSum);

                if (remainder == 0 || twoX.count(remainder)) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};