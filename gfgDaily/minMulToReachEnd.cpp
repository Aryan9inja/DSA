#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(vector<int>& arr, int start, int end) {
        if (start == end)
            return 0;
        vector<bool> visited(1000, 0);

        queue<int> q;
        q.push(start);
        visited[start] = true;
        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int front = q.front();
                q.pop();

                for (int a : arr) {
                    int x = ((front % 1000) * (a % 1000)) % 1000;

                    if (x == end)
                        return steps + 1;

                    if (!visited[x]) {
                        q.push(x);
                        visited[x] = true;
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};
