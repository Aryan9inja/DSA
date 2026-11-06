#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
        vector<int>& queries) {
        sort(logs.begin(), logs.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[1] < b[1];
            });

        int q_size = queries.size();
        vector<pair<int, int>> sorted_queries(q_size);
        for (int i = 0; i < q_size; ++i) {
            sorted_queries[i] = { queries[i], i };
        }
        sort(sorted_queries.begin(), sorted_queries.end());

        vector<int> ans(q_size);
        vector<int> count(n + 1, 0);
        int active_servers = 0;
        int left = 0, right = 0;
        int m = logs.size();

        for (auto& [q_time, idx] : sorted_queries) {
            while (right < m && logs[right][1] <= q_time) {
                int server_id = logs[right][0];
                if (count[server_id] == 0) {
                    active_servers++;
                }
                count[server_id]++;
                right++;
            }

            while (left < m && logs[left][1] < q_time - x) {
                int server_id = logs[left][0];
                count[server_id]--;
                if (count[server_id] == 0) {
                    active_servers--;
                }
                left++;
            }

            ans[idx] = n - active_servers;
        }

        return ans;
    }
};