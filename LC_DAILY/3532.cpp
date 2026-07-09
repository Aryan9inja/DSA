#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
        vector<vector<int>>& queries) {
        vector<int> component(n, 0);
        int componentNo = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                componentNo++;
            }
            component[i] = componentNo;
        }

        vector<bool> res;
        res.reserve(queries.size());
        for (const auto& q : queries) {
            if (component[q[0]] == component[q[1]]) {
                res.push_back(true);
            }
            else {
                res.push_back(false);
            }
        }

        return res;
    }
};