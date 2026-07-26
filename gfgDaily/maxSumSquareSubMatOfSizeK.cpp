#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();

        vector<int> colSum(n, 0);
        int res = INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                colSum[j] += mat[i][j];
                if (i >= k) {
                    colSum[j] -= mat[i - k][j];
                }
            }

            if (i >= k - 1) {
                int winSum = 0;
                for (int j = 0; j < n; j++) {
                    winSum += colSum[j];
                    if (j >= k) {
                        winSum -= colSum[j - k];
                    }
                    if (j >= k - 1) {
                        res = max(res, winSum);
                    }
                }
            }
        }

        return res;
    }
};
