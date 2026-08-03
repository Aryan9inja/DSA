#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumWithK(vector<int>& arr, int k) {
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }

        int last = 0;
        int j = 0;
        int maxSum = INT_MIN;
        maxSum = max(maxSum, sum);

        for (int i = k; i < arr.size(); i++) {
            sum = sum + arr[i];

            last = last + arr[j++];

            maxSum = max(maxSum, sum);

            if (last < 0) {
                sum = sum - last;
                maxSum = max(maxSum, sum);
                last = 0;
            }
        }

        return maxSum;
    }

};
