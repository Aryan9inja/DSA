#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestArea(int n, int m, vector<vector<int>>& arr) {
        vector<int> blockedRows;
        vector<int> blockedCols;

        for (auto& e : arr) {
            blockedRows.push_back(e[0]);
            blockedCols.push_back(e[1]);
        }

        blockedRows.push_back(0);
        blockedRows.push_back(n + 1);

        blockedCols.push_back(0);
        blockedCols.push_back(m + 1);

        sort(blockedRows.begin(), blockedRows.end());
        sort(blockedCols.begin(), blockedCols.end());

        int maxRowGap = 0;
        int maxColGap = 0;

        for (int i = 1; i < blockedRows.size(); i++) {
            maxRowGap = max(maxRowGap, blockedRows[i] - blockedRows[i - 1] - 1);
        }

        for (int i = 1; i < blockedCols.size(); i++) {
            maxColGap = max(maxColGap, blockedCols[i] - blockedCols[i - 1] - 1);
        }

        return maxColGap * maxRowGap;
    }
};
