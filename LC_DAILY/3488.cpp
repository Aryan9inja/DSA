#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int findMinDist(int q, vector<int>& indices, int n) {
        auto it = lower_bound(indices.begin(), indices.end(), q);
        int pos = distance(indices.begin(), it);

        int prevIndex = indices[(pos - 1 + indices.size()) % indices.size()];
        int nextIndex = indices[(pos + 1) % indices.size()];

        auto getDist = [&](int target) {
            int dis = abs(q - target);
            return min(dis, n - dis);
        };

        return min(getDist(prevIndex), getDist(nextIndex));
    }

public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> idxMap;

        for (int i = 0; i < nums.size(); i++) {
            idxMap[nums[i]].push_back(i);
        }

        vector<int> ans;
        for (int q : queries) {
            int element = nums[q];
            vector<int>& indices = idxMap[element];

            if (indices.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int minDist = findMinDist(q, indices, nums.size());
            ans.push_back(minDist);
        }
        return ans;
    }
};