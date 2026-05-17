#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 1, right = n;
        int ans = n;

        auto hasUniqueSubarray =
            [&](int L) {
                if (L == 0)
                    return false;

                vector<uint64_t> hashes;
                hashes.reserve(n - L + 1);

                uint64_t currHash = 0;
                uint64_t highestPow = 1;
                const uint64_t BASE = 1000000007ULL;

                for (int i = 0; i < L; ++i) {
                    currHash = currHash * BASE + nums[i];
                    if (i < L - 1) {
                        highestPow = highestPow * BASE;
                    }
                }
                hashes.push_back(currHash);

                for (int i = L; i < n; ++i) {
                    currHash = currHash - nums[i - L] * highestPow;
                    currHash = currHash * BASE + nums[i];
                    hashes.push_back(currHash);
                }

                sort(hashes.begin(), hashes.end());
                int m = hashes.size();

                for (int i = 0; i < m; ++i) {
                    bool uniLeft = (i == 0 || hashes[i] != hashes[i - 1]);
                    bool uniRight = (i == m - 1 || hashes[i] != hashes[i + 1]);

                    if (uniLeft && uniRight)
                        return true;
                }

                return false;
            };

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (hasUniqueSubarray(mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};