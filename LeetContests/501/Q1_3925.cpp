#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> rev = nums;
        reverse(rev.begin(), rev.end());

        nums.insert(nums.end(), rev.begin(), rev.end());
        return nums;
    }
};