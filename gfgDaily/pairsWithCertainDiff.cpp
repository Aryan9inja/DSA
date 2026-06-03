#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumDiffPairs(vector<int>& arr, int k) {
        int n = arr.size();

        sort(arr.begin(), arr.end());

        int maxSum = 0;

        for (int i = n - 1; i > 0; i--) {
            if (arr[i] - arr[i - 1] < k) {
                maxSum += (arr[i] + arr[i - 1]);
                i--;
            }
        }

        return maxSum;
    }
};
