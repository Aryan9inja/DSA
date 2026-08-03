#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
        int m = a.size();

        vector<int> diff(n + 1, 0);
        for (int i = 0; i < m; i++) {
            int l = a[i];
            int r = b[i];
            int v = k[i];

            diff[l] += v;
            diff[r + 1] -= v;
        }

        int sum = 0;
        int ans = INT_MIN;
        for (const int& d : diff) {
            sum += d;
            ans = max(ans, sum);
        }

        return ans;
    }
};