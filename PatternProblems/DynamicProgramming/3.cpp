#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int robLinear(vector<int>& nums, int start, int end) {
        int next1 = 0;
        int next2 = 0;

        for (int i = end; i >= start; i--) {
            int rob = nums[i] + next2;
            int skip = next1;

            int curr = max(rob, skip);
            next2 = next1;
            next1 = curr;
        }

        return next1;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        int skipFirst = robLinear(nums, 1, n - 1);

        int skipLast = robLinear(nums, 0, n - 2);

        return max(skipFirst, skipLast);
    }
};