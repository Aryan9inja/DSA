#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;
        int i = 0;
        while (i < nums.size()) {
            int currCnt = 0;
            int curr = nums[i];

            while (i < nums.size() && nums[i] == curr) {
                if (currCnt < k) {
                    currCnt++;
                }
                i++;
            }

            for (int j = 0; j < currCnt; j++) {
                ans.push_back(curr);
            }
        }

        return ans;
    }
};