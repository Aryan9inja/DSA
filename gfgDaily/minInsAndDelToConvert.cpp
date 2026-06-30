#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsAndDel(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();

        // Stores position of elements in b
        vector<int> pos(100001, -1);
        for (int i = 0; i < m; i++) {
            pos[b[i]] = i;
        }

        // Stores position of items availabe
        // in both a and b
        // from a
        vector<int> vec;
        for (int i = 0; i < n; i++) {
            if (pos[a[i]] != -1)
                vec.push_back(pos[a[i]]);
        }

        // Stores longest increasing subsequence
        vector<int> lis;
        // Build LIS
        for (int x : vec) {
            auto it = lower_bound(lis.begin(), lis.end(), x);

            if (it == lis.end()) {
                lis.push_back(x);
            }
            else {
                *it = x;
            }
        }

        int L = lis.size();

        return n + m - 2 * L;
    }
};
