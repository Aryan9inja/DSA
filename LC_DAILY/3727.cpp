#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans = 0;
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) < abs(b);
            });

        int i = 0;
        int j = nums.size() - 1;

        for (int k = 0; k < nums.size(); k++) {
            if (k & 1) {
                long long val = nums[i++];
                ans -= val * val;
            }
            else {
                long long val = nums[j--];
                ans += val * val;
            }
        }

        return ans;
    }
};