#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        set<vector<int>> visited(points.begin(), points.end());
        if (visited.count(target))
            return 0;

        vector<vector<int>> current_layer = points;

        for (int k = 1; k <= 32; k++) {
            vector<vector<int>> next_layer;

            vector<vector<int>> all_points(visited.begin(), visited.end());

            set<vector<int>> found_this_gen;

            for (int i = 0; i < current_layer.size(); ++i) {
                for (int j = 0; j < all_points.size(); ++j) {
                    vector<int> c(3);
                    for (int d = 0; d < 3; ++d) {
                        long long sum =
                            (long long)current_layer[i][d] + all_points[j][d];
                        c[d] = (sum >= 0) ? (sum / 2) : ((sum - 1) / 2);
                    }

                    if (c == target)
                        return k;

                    if (visited.find(c) == visited.end() &&
                        found_this_gen.find(c) == found_this_gen.end()) {
                        found_this_gen.insert(c);
                        next_layer.push_back(c);
                    }
                }
            }

            if (next_layer.empty())
                break;
            for (auto& p : next_layer)
                visited.insert(p);
            current_layer = next_layer;
        }

        return -1;
    }
};