#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> minSuff(n);
        minSuff[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            minSuff[i] = min(minSuff[i + 1], nums[i]);
        }

        int maxi = -1;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            int score = maxi - minSuff[i];
            if (score <= k) return i;
        }

        return -1;
    }
};