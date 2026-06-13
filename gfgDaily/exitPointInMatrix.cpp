#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        int i = 0, j = 0;
        int dir = 0;

        while (true) {
            dir = (dir + mat[i][j]) % 4;

            if (mat[i][j] == 1) {
                mat[i][j] = 0;
            }
            if (dir == 0) {
                j++;
            }
            else if (dir == 1) {
                i++;
            }
            else if (dir == 2) {
                j--;
            }
            else if (dir == 3) {
                i--;
            }

            if (i < 0) {
                i++;
                break;
            }
            else if (i == mat.size()) {
                i--;
                break;
            }
            else if (j < 0) {
                j++;
                break;
            }
            else if (j == mat[0].size()) {
                j--;
                break;
            }
        }

        return { i,j };
    }
};
