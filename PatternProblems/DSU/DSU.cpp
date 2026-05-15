#include<bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent;
public:
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return;
        parent[pu] = pv;
    }
};

class DSU_BY_SIZE {
    vector<int> parent, size;
public:
    DSU_BY_SIZE(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    void unionBySize(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class DSU_BY_RANK {
    vector<int> parent, rank;
public:
    DSU_BY_RANK(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    void unionByRank(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return;
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};