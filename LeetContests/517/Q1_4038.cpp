#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, int> blockCnt;

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                blockCnt[nums[i]]++;
            }
        }

        int ans = 0;
        for (const auto& [val, cnt] : blockCnt) {
            if (cnt == 1) {
                ans++;
            }
        }

        return ans;
    }
};