#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int ele = nums[(n - 1) / 2];

        int ans = 0;
        for (int& n : nums) {
            ans += abs(ele - n);
        }

        return ans;
    }
};