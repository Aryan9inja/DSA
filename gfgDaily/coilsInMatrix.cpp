#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> formCoils(int n) {
        int N = 4 * n;

        vector<vector<int>> mat(N, vector<int>(N));
        int x = 1;

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                mat[r][c] = x++;
            }
        }

        vector<int> coil1, coil2;

        vector<vector<bool>> visited(N, vector<bool>(N, false));

        int r1 = 0, c1 = 0;
        int r2 = N - 1, c2 = N - 1;

        int dr1[] = { 1, 0, -1, 0 };
        int dc1[] = { 0, 1, 0, -1 };

        int dr2[] = { -1, 0, 1, 0 };
        int dc2[] = { 0, -1, 0, 1 };

        int d1 = 0;
        int d2 = 0;

        while (true) {
            bool moved = false;

            // ---- Coil 1 ----
            if (!visited[r1][c1]) {
                coil1.push_back(mat[r1][c1]);
                visited[r1][c1] = true;
                moved = true;
            }

            int nr1 = r1 + dr1[d1];
            int nc1 = c1 + dc1[d1];

            if (nr1 >= 0 && nr1 < N &&
                nc1 >= 0 && nc1 < N &&
                !visited[nr1][nc1]) {
                r1 = nr1;
                c1 = nc1;
            }
            else {
                d1 = (d1 + 1) % 4;

                nr1 = r1 + dr1[d1];
                nc1 = c1 + dc1[d1];

                if (nr1 >= 0 && nr1 < N &&
                    nc1 >= 0 && nc1 < N &&
                    !visited[nr1][nc1]) {
                    r1 = nr1;
                    c1 = nc1;
                }
            }

            // ---- Coil 2 ----
            if (!visited[r2][c2]) {
                coil2.push_back(mat[r2][c2]);
                visited[r2][c2] = true;
                moved = true;
            }

            int nr2 = r2 + dr2[d2];
            int nc2 = c2 + dc2[d2];

            if (nr2 >= 0 && nr2 < N &&
                nc2 >= 0 && nc2 < N &&
                !visited[nr2][nc2]) {
                r2 = nr2;
                c2 = nc2;
            }
            else {
                d2 = (d2 + 1) % 4;

                nr2 = r2 + dr2[d2];
                nc2 = c2 + dc2[d2];

                if (nr2 >= 0 && nr2 < N &&
                    nc2 >= 0 && nc2 < N &&
                    !visited[nr2][nc2]) {
                    r2 = nr2;
                    c2 = nc2;
                }
            }

            if (!moved)
                break;
        }

        return { coil1, coil2 };
    }
};
