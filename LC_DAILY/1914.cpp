#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; layer++) {
            vector<int> vals;

            int top = layer, left = layer;
            int bottom = m - layer - 1;
            int right = n - layer - 1;

            // top row
            for (int i = left; i < right; i++) {
                vals.push_back(grid[top][i]);
            }

            // right column
            for (int i = top; i < bottom; i++) {
                vals.push_back(grid[i][right]);
            }

            // bottom row
            for (int i = right; i > left; i--) {
                vals.push_back(grid[bottom][i]);
            }

            // left column
            for (int i = bottom; i > top; i--) {
                vals.push_back(grid[i][left]);
            }

            int len = vals.size();
            int shift = k % len;
            rotate(vals.begin(), vals.begin() + shift, vals.end());

            // Adding back elements
            int idx = 0;
            // top row
            for (int i = left; i < right; i++) {
                grid[top][i] = vals[idx++];
            }

            // right column
            for (int i = top; i < bottom; i++) {
                grid[i][right] = vals[idx++];
            }

            // bottom row
            for (int i = right; i > left; i--) {
                grid[bottom][i] = vals[idx++];
            }

            // left column
            for (int i = bottom; i > top; i--) {
                grid[i][left] = vals[idx++];
            }
        }
        return grid;
    }
};