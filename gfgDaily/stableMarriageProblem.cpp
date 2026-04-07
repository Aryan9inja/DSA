#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> stableMarriage(vector<vector<int>>& men, vector<vector<int>>& women) {
        int n = men.size();
        vector<int> wife(n, -1);      // woman -> man
        vector<int> husband(n, -1);   // man -> woman
        vector<int> next(n, 0);       // next woman to propose

        // rank[w][m] = preference order of man m for woman w
        vector<vector<int>> rank(n, vector<int>(n));

        for (int w = 0; w < n; w++) {
            for (int i = 0; i < n; i++) {
                rank[w][women[w][i]] = i;
            }
        }

        queue<int> freeMen;
        for (int i = 0; i < n; i++) freeMen.push(i);

        while (!freeMen.empty()) {
            int m = freeMen.front();
            freeMen.pop();

            int w = men[m][next[m]];
            next[m]++;

            if (wife[w] == -1) {
                // woman is free
                wife[w] = m;
                husband[m] = w;
            }
            else {
                int m2 = wife[w];

                if (rank[w][m] < rank[w][m2]) {
                    // she prefers new man
                    wife[w] = m;
                    husband[m] = w;

                    husband[m2] = -1;
                    freeMen.push(m2);
                }
                else {
                    // she rejects
                    freeMen.push(m);
                }
            }
        }

        return husband;
    }
};