#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {
            int a = nums[i];
            int b = nums[n - i - 1];
            int low = min(a, b) + 1;
            int high = max(a, b) + limit;

            int sum = a + b;

            // Initially every target requires 2 moves
            diff[2] += 2;
            diff[limit * 2 + 1] -= 2;

            // From low target requires one move upto high
            diff[low] -= 1;
            diff[high + 1] += 1;

            // For exact sum target requires zero moves
            diff[sum] -= 1;
            diff[sum + 1] += 1;
        }

        int ans = INT_MAX;
        int moves = 0;

        for (int target = 2; target <= 2 * limit; target++) {
            moves += diff[target];
            ans = min(ans, moves);
        }

        return ans;
    }
};