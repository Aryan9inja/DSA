#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        bool hasOdd = false;
        int mini = nums[0];

        for (int& n : nums) {
            if (n < mini) {
                mini = n;
            }

            if (n & 1) hasOdd = true;
        }

        if (mini & 1) return true;
        return !hasOdd;
    }
};