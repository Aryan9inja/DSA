#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) return nums;

        vector<int> max_left(n, INT_MIN);
        int current_max_left = nums[0];
        for (int i = 1; i < n; i++) {
            max_left[i] = current_max_left;
            current_max_left = max(current_max_left, nums[i]);
        }

        vector<int> max_right(n, INT_MIN);
        int current_max_right = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            max_right[i] = current_max_right;
            current_max_right = max(current_max_right, nums[i]);
        }

        vector<int> valid;

        for (int i = 0; i < n; i++) {
            if (i == 0 || i == n - 1) {
                valid.push_back(nums[i]);
            }
            else if (nums[i] > max_left[i] || nums[i] > max_right[i]) {
                valid.push_back(nums[i]);
            }
        }
        return valid;
    }
};