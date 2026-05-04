#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);
        int even = 0, odd = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] % 2 == 0) {
                ans[i] = odd;
                even++;
            }
            else {
                ans[i] = even;
                odd++;
            }
        }

        return ans;
    }
};