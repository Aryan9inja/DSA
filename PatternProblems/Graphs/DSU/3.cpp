// LC: 1584. Min Cost to Connect All Points
#include<bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, size;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int u) {
        if (parent[u] == u)
            return u;
        return parent[u] = find(parent[u]);
    }
    bool unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv)
            return false;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        return true;
    }
};

class Solution {
public:
    static bool comparator(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                auto u = points[i];
                auto v = points[j];
                int w = abs(u[0] - v[0]) + abs(u[1] - v[1]);

                edges.push_back({i, j, w});
            }
        }

        sort(edges.begin(), edges.end(), comparator);

        DSU dsu(n);
        int ans = 0;
        for (const auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if (dsu.unite(u, v)) {
                ans += w;
            }
        }

        return ans;
    }
};