#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        vector<vector<int>> ans;

        int n = arr.size();

        int i = 0;
        int level = 0;
        while (i < n) {
            int levelMax = pow(2, level);
            int sz = min(levelMax, n - i);
            vector<int> temp;
            temp.reserve(sz);

            while (sz--) {
                temp.push_back(arr[i]);
                i++;
            }

            ans.push_back(temp);
            level++;
        }

        for (auto& row : ans) {
            sort(row.begin(), row.end());
        }

        return ans;
    }
};
