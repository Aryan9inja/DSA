#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digSum(int dig) {
        int sum = 0;
        while (dig > 0) {
            int d = dig % 10;
            dig /= 10;

            sum += d;
        }
        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (digSum(nums[i]) == i) {
                return i;
            }
        }
        return -1;
    }
};