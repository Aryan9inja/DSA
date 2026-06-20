#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> optimalArray(vector<int>& a) {
        int n = a.size();

        vector<int> ans(n);
        ans[0] = 0;

        for (int i = 1; i < n; i++) {
            // prev ans + curr median
            ans[i] = ans[i - 1] + (a[i] - a[i / 2]);
        }

        return ans;
    }
};
