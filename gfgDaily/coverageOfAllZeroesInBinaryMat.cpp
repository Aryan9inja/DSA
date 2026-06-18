#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCoverage(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();

        int res = 0;
        for (int i = 0; i < r; i++) {
            bool isOne = false;

            for (int j = 0; j < c; j++) {
                if (mat[i][j] == 1)
                    isOne = true;
                else if (isOne)
                    res++;
            }

            isOne = false;

            for (int j = c - 1; j >= 0; j--) {
                if (mat[i][j] == 1)
                    isOne = true;

                else if (isOne)
                    res++;
            }
        }

        for (int j = 0; j < c; j++) {
            bool isOne = false; 

            for (int i = 0; i < r; i++) {
                if (mat[i][j] == 1)
                    isOne = true;

                else if (isOne)
                    res++;
            }

            isOne = false;

            for (int i = r - 1; i >= 0; i--) {
                if (mat[i][j] == 1)
                    isOne = true;

                else if (isOne)
                    res++;
            }
        }

        return res;
    }
};
