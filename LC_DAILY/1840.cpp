#include<bits/stdc++.h>
using namespace std;

class Solution {
    int yCap(vector<int>& l, vector<int>& r) {
        int x1 = l[0], y1 = l[1], x2 = r[0], y2 = r[1];
        return min(y2, y1 + abs(x2 - x1));
    }

    int yPeak(vector<int>& l, vector<int>& r) {
        int x1 = l[0], y1 = l[1], x2 = r[0], y2 = r[1];
        return (y1 + y2 + x2 - x1) >> 1;
    }

public:
    int maxBuilding(int num, vector<vector<int>>& restrictions) {
        restrictions.push_back({ 1, 0 });
        sort(restrictions.begin(), restrictions.end());
        int n = restrictions.size();

        for (int i = 1; i < n; i++) {
            restrictions[i][1] = yCap(restrictions[i - 1], restrictions[i]);
        }

        for (int i = n - 2; i >= 0; i--) {
            restrictions[i][1] = yCap(restrictions[i + 1], restrictions[i]);
        }

        int res = 0;
        for (int i = 1; i < n; i++) {
            res = max(res, yPeak(restrictions[i - 1], restrictions[i]));
        }

        return max(res, restrictions[n - 1][1] + num - restrictions[n - 1][0]);
    }
};