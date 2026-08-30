#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)
            return n;

        int min_idx = 0;
        int max_idx = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] < nums[min_idx])
                min_idx = i;
            if (nums[i] > nums[max_idx])
                max_idx = i;
        }

        int a = min(min_idx, max_idx);
        int b = max(min_idx, max_idx);

        int both_front = b + 1;
        int both_back = n - a;
        int split_ends = (a + 1) + (n - b);

        return min({ both_front, both_back, split_ends });
    }
};