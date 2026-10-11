#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (n % (i + 1) == 0) ans += x * x;
        }

        return ans;
    }
};