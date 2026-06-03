#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> idxMap;

        for (int i = 0; i < arr.size(); i++) {
            idxMap[arr[i]].push_back(i);
        }

        vector<int> res;
        res.reserve(queries.size());

        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];
            int x = q[2];

            if (idxMap[x].size() == 0) {
                res.push_back(0);
                continue;
            }

            auto left = lower_bound(idxMap[x].begin(), idxMap[x].end(), l);
            auto right = upper_bound(idxMap[x].begin(), idxMap[x].end(), r);

            res.push_back(right - left);
        }

        return res;
    }
};
