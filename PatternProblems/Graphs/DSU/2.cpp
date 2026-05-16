// LC 684 - Redundant Connection
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
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        DSU dsu(n + 1);

        for (const auto& ed : edges) {
            int u = ed[0];
            int v = ed[1];

            if (!dsu.unite(u, v)) {
                return ed;
            }
        }

        return {};
    }
};