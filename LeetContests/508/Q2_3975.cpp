#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        if (occupiedIntervals.empty()) return {};

        sort(occupiedIntervals.begin(), occupiedIntervals.end());
        vector<vector<int>> merge;

        for (const auto& in : occupiedIntervals) {
            if (merge.empty()) {
                merge.push_back(in);
            }
            else {
                auto& last = merge.back();

                if (in[0] <= last[1] + 1) {
                    last[1] = max(last[1], in[1]);
                }
                else {
                    merge.push_back(in);
                }
            }
        }

        vector<vector<int>> ans;
        for (const auto& in : merge) {
            int s = in[0];
            int e = in[1];

            if (e < freeStart || s > freeEnd) {
                ans.push_back({ s,e });
            }
            else {
                if (s < freeStart) {
                    ans.push_back({ s, freeStart - 1 });
                }
                if (e > freeEnd) {
                    ans.push_back({ freeEnd + 1, e });
                }
            }
        }

        return ans;
    }
};