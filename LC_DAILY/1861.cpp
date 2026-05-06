#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();
        vector<vector<char>> rotatedBox(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rotatedBox[i][j] = boxGrid[m - 1 - j][i];
            }
        }

        for (int i = 0; i < m; i++) {
            int posToFall = -1;
            for (int j = n - 1; j >= 0; j--) {
                char curr = rotatedBox[j][i];

                if (curr == '.' && posToFall == -1)
                    posToFall = j;
                else if (curr == '#' && posToFall != -1) {
                    swap(rotatedBox[j][i], rotatedBox[posToFall][i]);
                    posToFall--;
                }
                else if (curr == '*')
                    posToFall = -1;
            }
        }
        return rotatedBox;
    }
};