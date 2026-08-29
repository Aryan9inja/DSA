#include<bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> parent, size;

public:
    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);

        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (size[a] < size[b]) {
            swap(a, b);
        }

        parent[b] = a;
        size[a] += size[b];
    }
};

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        // value, idx
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({ nums[i], i });
        }

        sort(arr.begin(), arr.end());

        DSU dsu(n);

        for (int i = 1; i < n; i++) {
            if (arr[i].first - arr[i - 1].first <= limit) {
                dsu.unite(arr[i].second, arr[i - 1].second);
            }
        }

        unordered_map<int, vector<int>> groups;

        for (int i = 0; i < n; i++) {
            groups[dsu.find(i)].push_back(i);
        }

        for (auto& [root, indices] : groups) {
            vector<int> values;

            for (int idx : indices) {
                values.push_back(nums[idx]);
            }

            sort(indices.begin(), indices.end());
            sort(values.begin(), values.end());

            for (int i = 0; i < indices.size(); i++) {
                nums[indices[i]] = values[i];
            }
        }

        return nums;
    }
};