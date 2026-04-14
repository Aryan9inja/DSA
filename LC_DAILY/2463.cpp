#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long solve(vector<int>& robot, vector<vector<int>>& factory, int robo,
                    int fctry, vector<vector<long long>>& dp) {
        if (robo == robot.size())
            return 0;
        if (fctry == factory.size())
            return 1e18;

        if (dp[robo][fctry] != -1)
            return dp[robo][fctry];

        long long ans = solve(robot, factory, robo, fctry + 1, dp);

        long long cost = 0;
        for (int x = 1; x <= factory[fctry][1]; x++) {
            if (robo + x - 1 >= robot.size())
                break;

            cost += abs(robot[robo + x - 1] - factory[fctry][0]);

            ans =
                min(ans, cost + solve(robot, factory, robo + x, fctry + 1, dp));
        }

        return dp[robo][fctry] = ans;
    }

    long long tabulation(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
        int m = factory.size();

        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 1e18));

        for (int j = 0; j <= m; j++)
            dp[n][j] = 0;

        for (int robo = n - 1; robo >= 0; robo--) {
            for (int fctry = m - 1; fctry >= 0; fctry--) {
                long long ans = dp[robo][fctry + 1];

                long long cost = 0;
                for (int x = 1; x <= factory[fctry][1]; x++) {
                    if (robo + x - 1 >= n)
                        break;

                    cost += abs(robot[robo + x - 1] - factory[fctry][0]);

                    ans = min(ans, cost + dp[robo + x][fctry + 1]);
                }

                dp[robo][fctry] = ans;
            }
        }
        return dp[0][0];
    }

public:
    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end(),
             [](vector<int> a, vector<int> b) { return a[0] < b[0]; });

        // vector<vector<long long>> dp(robot.size(),vector<long
        // long>(factory.size(), -1));

        // return solve(robot, factory, 0, 0, dp);

        return tabulation(robot, factory);
    }
};
