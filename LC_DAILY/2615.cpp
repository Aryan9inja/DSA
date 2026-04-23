#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);
        unordered_map<int, vector<int>> indices;

        // Group indices by value
        for (int i = 0; i < n; i++) {
            indices[nums[i]].push_back(i);
        }

        // For each unique value, the indices are already sorted
        for (auto const& [val, idxList] : indices) {
            int m = idxList.size();
            if (m <= 1)
                continue;

            // Create a local prefix sum of the indices
            vector<long long> p(m + 1, 0);
            for (int i = 0; i < m; i++)
                p[i + 1] = p[i] + idxList[i];

            // Apply the same math: (count * current_idx) -
            // sum_of_smaller_indices
            // + (sum_of_larger_indices - count * current_idx)
            for (int i = 0; i < m; i++) {
                long long leftContri = (long long)i * idxList[i] - p[i];
                long long rightContri =
                    (p[m] - p[i + 1]) - (long long)(m - i - 1) * idxList[i];
                ans[idxList[i]] = leftContri + rightContri;
            }
        }
        return ans;
    }
};