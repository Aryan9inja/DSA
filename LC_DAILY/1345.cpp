#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);

        int ans = 0;

        vector<bool> vis(n, false);
        vis[0] = true;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int curr = q.front();
                q.pop();

                if (curr == n - 1)
                    return ans;

                if (curr + 1 < n && !vis[curr + 1]) {
                    q.push(curr + 1);
                    vis[curr + 1] = true;
                }

                if (curr - 1 >= 0 && !vis[curr - 1]) {
                    q.push(curr - 1);
                    vis[curr - 1] = true;
                }

                for (auto x : mp[arr[curr]]) {
                    if (!vis[x]) {
                        q.push(x);
                        vis[x] = true;
                    }
                }

                mp.erase(arr[curr]);
            }

            ans++;
        }
        return -1;
    }
};