#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPerimeter(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int perimeter = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    perimeter += 4;

                    if (i > 0 && mat[i - 1][j] == 1)
                        perimeter -= 2;
                    if (j > 0 && mat[i][j - 1] == 1)
                        perimeter -= 2;
                }
            }
        }

        return perimeter;
    }
};
