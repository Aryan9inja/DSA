#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int ele = nums[n / 2];

        int cnt = 0;
        for (const int& n : nums) {
            if (n == ele) cnt++;
        }

        return cnt == 1;
    }
};