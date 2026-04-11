// GFG - Max subarray of size k

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int windowSum = 0;

        // first window
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }

        int maxSum = windowSum;

        // slide window
        for (int i = k; i < arr.size(); i++) {
            windowSum += arr[i];        // add next
            windowSum -= arr[i - k];    // remove first

            maxSum = max(maxSum, windowSum);
        }

        return maxSum;
    }
};