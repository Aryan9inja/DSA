#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long total_ops = 0;

        for (int i = 1; i < nums.size(); i++) {
            // there is dip
            if (nums[i] < nums[i - 1]) {
                int diff = nums[i - 1] - nums[i];
                total_ops += diff;
            }
        }

        return total_ops;
    }
};