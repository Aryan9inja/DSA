#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> best(n + 1, INT_MAX);

        int left = 0;
        int sum = 0;
        int ans = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target && left <= right) {
                sum -= arr[left];
                left++;
            }

            best[right + 1] = best[right];

            if (sum == target) {
                int len = right - left + 1;

                if (best[left] != INT_MAX) {
                    ans = min(ans, best[left] + len);
                }

                best[right + 1] = min(best[right + 1], len);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};