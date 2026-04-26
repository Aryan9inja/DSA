#include<bits/stdc++.h>
using namespace std;

// class Solution {
// private:
//     long long solve(vector<int>& nums, int k, int idx, int prevIdx,
//                     int expectedDir) {
//         if (idx >= nums.size())
//             return 0;

//         // Case 1 : skip
//         long long maxScore = solve(nums, k, idx + 1, prevIdx, expectedDir);

//         // Case 2 : include
//         if (prevIdx == -1 || idx - prevIdx >= k) {
//             // Sub-Case 1 : first element
//             if (prevIdx == -1) {
//                 long long pickLarger =
//                     nums[idx] + solve(nums, k, idx + 1, idx, 1);
//                 long long pickSmaller =
//                     nums[idx] + solve(nums, k, idx + 1, idx, -1);

//                 maxScore = max({maxScore, pickLarger, pickSmaller});
//             }
//             // Sub-Case 2 : picking larger
//             else if (expectedDir == 1 && nums[idx] > nums[prevIdx]) {
//                 long long score = nums[idx] + solve(nums, k, idx + 1, idx, -1);
//                 maxScore = max(maxScore, score);
//             } else if (expectedDir == -1 && nums[idx] < nums[prevIdx]) {
//                 long long score = nums[idx] + solve(nums, k, idx + 1, idx, 1);
//                 maxScore = max(maxScore, score);
//             }
//         }

//         return maxScore;
//     }

// public:
//     long long maxAlternatingSum(vector<int>& nums, int k) {
//         int n = nums.size();
//         return solve(nums, k, 0, -1, 0);
//     }
// };

class Solution {
    // A Binary Indexed Tree to maintain prefix maximums
    struct FenwickTree {
        int n;
        vector<long long> tree;

        FenwickTree(int n) : n(n), tree(n + 1, 0) {}

        void update(int i, long long val) {
            for (; i <= n; i += i & -i) {
                tree[i] = max(tree[i], val);
            }
        }

        long long query(int i) {
            long long mx = 0;
            for (; i > 0; i -= i & -i) {
                mx = max(mx, tree[i]);
            }
            return mx;
        }
    };

public:
    long long maxAlternatingSum(vector<int>& nums, int k) {
        int n = nums.size();
        int max_val = 0;
        for (int x : nums) {
            max_val = max(max_val, x);
        }

        // bitTrough stores maximum scores of sequences ending in a Trough.
        // It's queried using standard values (to find strictly smaller elements).
        FenwickTree bitTrough(max_val);

        // bitPeakRev stores maximum scores of sequences ending in a Peak.
        // To find strictly greater elements easily using a prefix tree, 
        // we map value `x` to a reversed index: `max_val - x + 1`.
        FenwickTree bitPeakRev(max_val);

        vector<long long> dpPeak(n, 0);
        vector<long long> dpTrough(n, 0);

        long long max_score = 0;

        for (int i = 0; i < n; i++) {
            int val = nums[i];

            // Only add elements to the Fenwick Trees if they are >= k distance away
            if (i >= k) {
                int addIdx = i - k;
                int addVal = nums[addIdx];

                // We add the DP results of the element that just became valid
                bitTrough.update(addVal, dpTrough[addIdx]);
                bitPeakRev.update(max_val - addVal + 1, dpPeak[addIdx]);
            }

            // Case 1: Current element acts as a Peak (prev must be a Trough < val)
            // Query for max Trough score from values 1 to (val - 1)
            dpPeak[i] = val + bitTrough.query(val - 1);

            // Case 2: Current element acts as a Trough (prev must be a Peak > val)
            // Reverse mapping to find max Peak score from values (val + 1) to max_val
            dpTrough[i] = val + bitPeakRev.query(max_val - val);

            // Keep track of the global maximum sequence score
            max_score = max({ max_score, dpPeak[i], dpTrough[i] });
        }

        return max_score;
    }
};