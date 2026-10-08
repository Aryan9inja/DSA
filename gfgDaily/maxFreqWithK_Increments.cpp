#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());

        long long windowSum = 0;
        int left = 0;
        int res = 1;

        for (int right = 0; right < arr.size(); ++right) {
            windowSum += arr[right];

            while (1LL * arr[right] * (right - left + 1) - windowSum > k) {
                windowSum -= arr[left];
                ++left;
            }

            res = max(res, right - left + 1);
        }

        return res;
    }
};
