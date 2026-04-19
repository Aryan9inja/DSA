#include<bits/stdc++.h>
using namespace std;

class Cell {
public:
    int row;
    int col;
    int color;
    int time;

    Cell(int r, int c, int cl, int t) {
        row = r;
        col = c;
        color = cl;
        time = t;
    }
};

class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<vector<int>> timeGrid(n, vector<int>(m, -1));

        queue<Cell> q;
        for (auto& s : sources) {
            int row = s[0];
            int col = s[1];
            int color = s[2];

            if (timeGrid[row][col] == -1) {
                grid[row][col] = color;
                timeGrid[row][col] = 0;
            } else {
                grid[row][col] = max(grid[row][col], color);
            }
        }

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (timeGrid[row][col] == 0) {
                    Cell temp(row, col, grid[row][col], 0);
                    q.push(temp);
                }
            }
        }

        int dirRow[4] = {-1, 1, 0, 0};
        int dirCol[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            Cell curr = q.front();
            q.pop();

            if (grid[curr.row][curr.col] > curr.color)
                continue;

            for (int i = 0; i < 4; i++) {
                int neighbourRow = curr.row + dirRow[i];
                int neighbourCol = curr.col + dirCol[i];

                if (neighbourRow >= 0 && neighbourRow < n &&
                    neighbourCol >= 0 && neighbourCol < m) {
                    int nextTime = curr.time + 1;

                    // Case : Uncolored
                    if (timeGrid[neighbourRow][neighbourCol] == -1) {
                        timeGrid[neighbourRow][neighbourCol] = nextTime;
                        grid[neighbourRow][neighbourCol] = curr.color;

                        Cell temp(neighbourRow, neighbourCol, curr.color,
                                  nextTime);
                        q.push(temp);
                    }
                    // Case : Same time conflict
                    else if (timeGrid[neighbourRow][neighbourCol] == nextTime) {
                        if (curr.color > grid[neighbourRow][neighbourCol]) {
                            grid[neighbourRow][neighbourCol] = curr.color;

                            Cell temp(neighbourRow, neighbourCol, curr.color,
                                  nextTime);
                            q.push(temp);
                        }
                    }
                }
            }
        }
        return grid;
    }
};