#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        vector<int> moves(n * n + 1, -1);
        vector<bool> vis(n * n + 1, false);

        for (int i = 0; i < lad.size(); i += 2) {
            moves[lad[i]] = lad[i + 1];
        }

        for (int i = 0; i < sn.size(); i += 2) {
            moves[sn[i]] = sn[i + 1];
        }

        queue<pair<int, int>> q;
        q.push({ 1, 0 });
        vis[1] = true;

        pair<int, int> curr;

        while (!q.empty()) {
            curr = q.front();
            q.pop();

            int pos = curr.first;
            int dist = curr.second;

            if (pos == n * n)
                return dist;

            for (int i = pos + 1; i <= pos + 6; i++) {
                if (vis[i])
                    continue;

                vis[i] = true;
                int dest = (moves[i] == -1) ? i : moves[i];
                q.push({ dest, dist + 1 });
            }
        }

        return -1;
    }
};
