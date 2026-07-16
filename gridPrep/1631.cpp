#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> effort(rows, vector<int>(cols, INT_MAX));
        effort[0][0] = 0;

        // < curr_effort, row , col >
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>>
            pq;

        pq.push({ 0, 0, 0 });

        static int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

        while (!pq.empty()) {
            auto [curr_effort, row, col] = pq.top();
            pq.pop();

            if (row == rows - 1 && col == cols - 1) {
                return curr_effort;
            }

            if (curr_effort > effort[row][col]) {
                continue;
            }

            for (auto& d : dir) {
                int newRow = row + d[0];
                int newCol = col + d[1];

                if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) {
                    continue;
                }

                int step_effort = abs(heights[newRow][newCol] - heights[row][col]);

                int new_effort = max(curr_effort, step_effort);

                if (new_effort < effort[newRow][newCol]) {
                    effort[newRow][newCol] = new_effort;
                    pq.push({ new_effort, newRow, newCol });
                }
            }
        }

        return 0;
    }
};

// Binary Search on Answer
/*
class Solution {
public:
    bool canReach(vector<vector<int>>& heights, int limit) {
        int rows = heights.size();
        int cols = heights[0].size();

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        q.push({0, 0});
        visited[0][0] = true;

        static int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            if (row == rows - 1 && col == cols - 1)
                return true;

            for (auto &d : dir) {
                int newRow = row + d[0];
                int newCol = col + d[1];

                if (newRow < 0 || newRow >= rows ||
                    newCol < 0 || newCol >= cols)
                    continue;

                if (visited[newRow][newCol])
                    continue;

                int diff = abs(heights[newRow][newCol] - heights[row][col]);

                if (diff <= limit) {
                    visited[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }
            }
        }

        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int low = 0;
        int high = 1'000'000; // Maximum possible height difference

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canReach(heights, mid))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};
*/