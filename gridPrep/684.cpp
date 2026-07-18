#include<bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> parent, size;

public:
    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    bool unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) return false;

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

        DSU uf(n + 1);

        for (const auto& e : edges) {
            int u = e[0];
            int v = e[1];

            if (!uf.unite(u, v)) {
                return e;
            }
        }

        return {};
    }
};