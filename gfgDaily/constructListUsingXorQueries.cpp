#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructList(vector<vector<int>>& queries) {
        int xr = 0;

        vector<int> ans;

        int n = queries.size();
        for (int i = n - 1; i >= 0; i--) {
            if (queries[i][0] == 0)
                ans.push_back(queries[i][1] ^ xr);
            else
                xr ^= queries[i][1];
        }

        ans.push_back(xr);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
