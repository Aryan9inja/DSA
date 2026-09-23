#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int formPyramid(vector<int>& arr) {
        int n = arr.size();

        int total = accumulate(arr.begin(), arr.end(), 0);

        vector<int> left(n), right(n);

        left[0] = 1;
        for (int i = 1; i < n; i++) {
            left[i] = min(left[i - 1] + 1, arr[i]);
        }

        right[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            right[i] = min(right[i + 1] + 1, arr[i]);
        }

        int minCost = INT_MAX;
        for (int i = 0; i < n; i++) {
            int peak = min(left[i], right[i]);

            int pyramidSum = peak * peak;

            minCost = min(minCost, total - pyramidSum);
        }

        return minCost;
    }
};