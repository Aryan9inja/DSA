#include<bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        DSU dsu(n);

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(isConnected[i][j]) {
                    dsu.unite(i, j);
                }
            }
        }

        int components = 0;

        for(int i = 0; i < n; i++) {
            if(dsu.find(i) == i) {
                components++;
            }
        }

        return components;
    }
};