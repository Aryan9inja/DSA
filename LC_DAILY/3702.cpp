#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int xor_res = 0;
        for (int& x : nums) {
            xor_res ^= x;
        }

        if (xor_res)
            return n;

        for (int& x : nums) {
            if (x == 0)
                continue;
            int temp = xor_res ^ x;
            if (temp)
                return n - 1;
        }

        return 0;
    }
};