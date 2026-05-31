#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        int n = nums.size();

        vector<int> suffixMEX(n);

        vector<bool> present(n + 2, false);
        int currMEX = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] <= n) {
                present[nums[i]] = true;
            }
            while (present[currMEX]) {
                currMEX++;
            }
            suffixMEX[i] = currMEX;
        }

        vector<int> res;

        vector<int> vis(n + 2, 0);
        int step = 1;
        int i = 0;

        while (i < n) {
            int target = suffixMEX[i];

            if (target == 0) {
                while (i < n) {
                    res.push_back(0);
                    i++;
                }
                break;
            }

            int cnt = 0;

            while (i < n && cnt < target) {
                int val = nums[i];
                if (val < target && vis[val] != step) {
                    vis[val] = step;
                    cnt++;
                }
                i++;
            }

            res.push_back(target);
            step++;
        }
        return res;
    }
};