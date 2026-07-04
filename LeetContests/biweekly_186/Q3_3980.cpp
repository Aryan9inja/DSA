#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int i, int prevPair, const string& s1, const string& s2) {
        if (i == n) {
            return (prevPair == 0) ? 0 : INF;
        }

        if (dp[i][prevPair] != -1) {
            return dp[i][prevPair];
        }

        int ops = INF;

        for (int pair = 0; pair <= 1; pair++) {
            if (i == n - 1 && pair == 1)
                continue;

            int k = prevPair + pair;
            int cost = 0;

            if (k == 0) {
                if (s1[i] == s2[i]) {
                    cost = 0;
                }
                else if (s1[i] == '0' && s2[i] == '1') {
                    cost = 1;
                }
                else {
                    cost = INF;
                }
            }
            else if (k == 1) {
                cost = (s1[i] == '0') + (s2[i] == '1');
            }
            else {
                cost = (s1[i] == '0') + 1 + (s2[i] == '1');
            }

            if (cost >= INF)
                continue;

            int totalCost = cost + pair;

            int next = solve(i + 1, pair, s1, s2);
            if (next != INF) {
                ops = min(ops, totalCost + next);
            }
        }

        return dp[i][prevPair] = ops;
    }

    int minOperations(string s1, string s2) {
        n = s1.length();
        dp.assign(n, vector<int>(2, -1));

        int ans = solve(0, 0, s1, s2);
        return (ans >= INF) ? -1 : ans;
    }
};