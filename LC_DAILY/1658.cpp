#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total - x;

        if (target < 0) return -1;
        if (target == 0) return n;

        int l = 0;
        int sum = 0;
        int longest = -1;

        for (int r = 0; r < n; r++) {
            sum += nums[r];

            while (l <= r && sum > target) {
                sum -= nums[l++];
            }

            if (sum == target) {
                longest = max(longest, r - l + 1);
            }
        }

        return longest == -1 ? -1 : n - longest;
    }
};