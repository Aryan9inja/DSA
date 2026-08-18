#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int largestInteger(vector<int>& nums, int k) {
//         vector<int> subarray_freq(51, 0);
//         vector<int> window_freq(51, 0);

//         for (int i = 0; i < k; i++) {
//             window_freq[nums[i]]++;
//         }
//         for (int i = 0; i < 51; i++) {
//             if (window_freq[i] > 0) {
//                 subarray_freq[i]++;
//             }
//         }

//         int i = 0, j = i + k;
//         while (j < nums.size()) {
//             window_freq[nums[i]]--;
//             window_freq[nums[j]]++;

//             for (int i = 0; i < 51; i++) {
//                 if (window_freq[i] > 0) {
//                     subarray_freq[i]++;
//                 }
//             }

//             i++;
//             j++;
//         }

//         for (int i = 50; i >= 0; i--) {
//             if (subarray_freq[i] == 1)
//                 return i;
//         }

//         return -1;
//     }
// };

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // Case 1: The window size is the whole array.
        // Everything is in exactly 1 subarray, so return the max element.
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // Count frequencies of all elements in the array
        vector<int> freq(51, 0);
        for (int num : nums) {
            freq[num]++;
        }

        // Case 2: Window size is 1.
        // We need the maximum element that appears exactly once.
        if (k == 1) {
            for (int i = 50; i >= 0; i--) {
                if (freq[i] == 1) {
                    return i;
                }
            }
            return -1;
        }

        // Case 3: 1 < k < n.
        // Only the very first and very last elements can possibly appear in
        // exactly 1 window.
        int res = -1;

        if (freq[nums[0]] == 1) {
            res = max(res, nums[0]);
        }
        if (freq[nums.back()] == 1) {
            res = max(res, nums.back());
        }

        return res;
    }
};