#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<pair<int, int>>> memo;

    pair<int, int> solve(vector<string>& board, int i, int j) {
        if (i < 0 || j < 0 || board[i][j] == 'X') {
            return { INT_MIN, 0 };
        }

        if (i == 0 && j == 0) {
            return { 0, 1 };
        }

        if (memo[i][j].first != -2) {
            return memo[i][j];
        }

        pair<int, int> up = solve(board, i - 1, j);
        pair<int, int> left = solve(board, i, j - 1);
        pair<int, int> diag = solve(board, i - 1, j - 1);

        int max_next_score = max({ up.first, left.first, diag.first });

        if (max_next_score == INT_MIN) {
            return memo[i][j] = { INT_MIN, 0 };
        }

        int total_ways = 0;
        int MOD = 1e9 + 7;

        if (up.first == max_next_score)
            total_ways = (total_ways + up.second) % MOD;
        if (left.first == max_next_score)
            total_ways = (total_ways + left.second) % MOD;
        if (diag.first == max_next_score)
            total_ways = (total_ways + diag.second) % MOD;

        int current_score = (board[i][j] == 'E' || board[i][j] == 'S')
            ? 0
            : (board[i][j] - '0');

        return memo[i][j] = { max_next_score + current_score, total_ways };
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();

        memo.assign(n, vector<pair<int, int>>(n, { -2, -2 }));

        pair<int, int> ans = solve(board, n - 1, n - 1);

        if (ans.first == INT_MIN)
            return { 0, 0 };
        return { ans.first, ans.second };
    }
};