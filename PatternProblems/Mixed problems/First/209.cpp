#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minCount = INT_MAX;
        int sum = 0;
        int left = 0;
        int right = 0;

        while (right < nums.size()) {
            sum += nums[right];
            while (sum >= target) {
                int count = right - left + 1;
                minCount = min(count, minCount);
                sum -= nums[left];
                left++;
            }
            right++;
        }

        if (minCount == INT_MAX)
            return 0;
        return minCount;
    }
};