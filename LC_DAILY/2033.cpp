#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> temp;

        for (auto& row : grid) {
            for (auto& val : row) {
                temp.push_back(val);
            }
        }

        // Step 1: Check feasibility
        int rem = temp[0] % x;
        for (int val : temp) {
            if (val % x != rem) return -1;
        }

        // Step 2: Sort
        sort(temp.begin(), temp.end());

        // Step 3: Median
        int median = temp[temp.size() / 2];

        // Step 4: Compute operations
        int ops = 0;
        for (int val : temp) {
            ops += abs(val - median) / x;
        }

        return ops;
    }
};