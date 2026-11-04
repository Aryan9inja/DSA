#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    priority_queue<int> low;
    priority_queue<int, vector<int>, greater<int>> high;

    unordered_map<int, int> delayedLow, delayedHigh;

    long long sumLow = 0, sumHigh = 0;
    int lowSize = 0, highSize = 0;

    void pruneLow() {
        while (!low.empty()) {
            int num = low.top();

            auto it = delayedLow.find(num);
            if (it == delayedLow.end())
                break;

            low.pop();

            if (--it->second == 0)
                delayedLow.erase(it);
        }
    }

    void pruneHigh() {
        while (!high.empty()) {
            int num = high.top();

            auto it = delayedHigh.find(num);
            if (it == delayedHigh.end())
                break;

            high.pop();

            if (--it->second == 0)
                delayedHigh.erase(it);
        }
    }

    void rebalance() {
        pruneLow();
        pruneHigh();

        if (lowSize > highSize + 1) {
            int num = low.top();
            low.pop();

            sumLow -= num;
            sumHigh += num;

            lowSize--;
            highSize++;

            high.push(num);
        }
        else if (lowSize < highSize) {
            int num = high.top();
            high.pop();

            sumHigh -= num;
            sumLow += num;

            highSize--;
            lowSize++;

            low.push(num);
        }

        pruneLow();
        pruneHigh();
    }

    void add(int num) {
        pruneLow();

        if (low.empty() || num <= low.top()) {
            low.push(num);
            sumLow += num;
            lowSize++;
        }
        else {
            high.push(num);
            sumHigh += num;
            highSize++;
        }

        rebalance();
    }

    void remove(int num) {
        pruneLow();
        pruneHigh();

        if (!low.empty() && num <= low.top()) {
            lowSize--;
            sumLow -= num;

            delayedLow[num]++;

            if (num == low.top())
                pruneLow();
        }
        else {
            highSize--;
            sumHigh -= num;

            delayedHigh[num]++;

            if (!high.empty() && num == high.top())
                pruneHigh();
        }

        rebalance();
    }

    long long getCost() {
        pruneLow();
        pruneHigh();

        long long median = low.top();

        return median * lowSize - sumLow + sumHigh - median * highSize;
    }

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        if (k == 0)
            return 0;

        if (x <= 0 || k * 1LL * x > n)
            return -1;

        // Calculate the cost of every window of size x.
        vector<long long> cost(n - x + 1);

        for (int i = 0; i < x; i++)
            add(nums[i]);

        cost[0] = getCost();

        for (int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);

            cost[i - x + 1] = getCost();
        }

        // DP for selecting exactly k non-overlapping windows.
        const long long INF = LLONG_MAX / 4;

        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INF));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {

                // Skip the current element.
                dp[i][j] = dp[i - 1][j];

                // Select a window ending at i - 1.
                if (i >= x && dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(dp[i][j], dp[i - x][j - 1] + cost[i - x]);
                }
            }
        }

        return dp[n][k];
    }
};
