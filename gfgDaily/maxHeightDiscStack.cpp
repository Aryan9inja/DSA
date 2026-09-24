#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    class FenwickTree {
        vector<int> tree;

    public:
        FenwickTree(int n) {
            tree.resize(n + 1, 0);
        }

        void update(int index, int value) {
            while (index < tree.size()) {
                tree[index] = max(tree[index], value);
                index += index & -index;
            }
        }

        int query(int index) {
            int result = 0;

            while (index > 0) {
                result = max(result, tree[index]);
                index -= index & -index;
            }

            return result;
        }
    };

    int maxStackHeight(vector<int>& r, vector<int>& h) {
        int n = r.size();

        vector<pair<int, int>> discs;

        for (int i = 0; i < n; i++)
            discs.push_back({ r[i], h[i] });

        // Equal radii are sorted by height in descending order.
        sort(discs.begin(), discs.end(), [](auto& a, auto& b) {
            if (a.first != b.first)
                return a.first < b.first;
            return a.second > b.second;
            });

        vector<int> heights;

        for (auto& disc : discs)
            heights.push_back(disc.second);

        sort(heights.begin(), heights.end());
        heights.erase(unique(heights.begin(), heights.end()), heights.end());

        FenwickTree bit(heights.size());

        int ans = 0;

        for (auto& disc : discs) {
            int height = disc.second;

            int index = lower_bound(
                heights.begin(), heights.end(), height
            ) - heights.begin() + 1;

            // Query only strictly smaller heights.
            int best = bit.query(index - 1);

            int currentHeight = best + height;

            bit.update(index, currentHeight);

            ans = max(ans, currentHeight);
        }

        return ans;
    }

};
