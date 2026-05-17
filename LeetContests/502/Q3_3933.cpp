#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int maxVal = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                maxVal = max(maxVal, matrix[i][j]);
            }
        }

        if(maxVal ==0) return 0;

        int maxV = maxVal + 1;

        vector<vector<vector<int>>> pref(n+1, vector<vector<int>>(m+1, vector<int>(maxV+1, 0)));

        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                int val = matrix[i-1][j-1];
                for(int v = 0; v<=maxV; ++v){
                    pref[i][j][v] = pref[i-1][j][v] + pref[i][j-1][v] - pref[i-1][j-1][v] + (val>=v ? 1 : 0);
                }
            }
        }

        auto countGreater = [&](int r1, int r2, int c1, int c2, int v){
            if (v>maxV) return 0;
            return pref[r2][c2][v] - pref[r1-1][c2][v] - pref[r2][c1-1][v] + pref[r1-1][c1-1][v];
        };

        int localMaxCnt = 0;

        for(int r = 0; r<n; ++r){
            for(int c = 0; c<m; ++c){
                int x = matrix[r][c];

                if(x==0) continue;

                int r1 = max(0, r-x);
                int r2 = min(n-1, r+x);
                int c1 = max(0, c-x);
                int c2 = min(m-1, c+x);

                int totalGreater = countGreater(r1+1, r2+1, c1+1, c2+1, x+1);

                int corners[4][2]={
                    {r-x, c-x},
                    {r-x, c+x},
                    {r+x, c-x},
                    {r+x, c+x}
                };

                for(auto & c : corners){
                    int cr = c[0];
                    int cc = c[1];

                    if(cr>=0 && cr<n && cc>=0 && cc<m){
                        if(matrix[cr][cc] > x){
                            totalGreater--;
                        }
                    }
                }

                if(totalGreater == 0) localMaxCnt++;
            }
        }
        return localMaxCnt;
    }
};