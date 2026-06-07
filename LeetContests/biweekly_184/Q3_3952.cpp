#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();
        long long maxSum = 0;
        int i = 0;

        while (i < n && s[i] == '1') {
            maxSum += nums[i];
            i++;
        }

        while (i < n) {
            long long currSum = nums[i];
            int currMin = nums[i];
            i++;

            while (i < n && s[i] == '1') {
                currSum += nums[i];
                currMin = min(currMin, nums[i]);
                i++;
            }

            maxSum += (currSum - currMin);
        }

        return maxSum;
    }
};