#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMean(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();

        // Build prefix sum
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }

        vector<int> result;

        for (auto& q : queries) {
            int left = q[0];
            int right = q[1];

            int rangeSum = prefix[right + 1] - prefix[left];
            int length = right - left + 1;

            result.push_back(rangeSum / length);
        }

        return result;
    }
};