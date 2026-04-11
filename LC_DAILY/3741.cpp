#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, pair<int, int>> mp;
        int mini = INT_MAX;

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (mp.find(num) == mp.end()) {
                mp[num] = {-1, i};
            } else {
                auto& [prev, last] = mp[num];

                if (prev != -1) {
                    int a = prev, b = last, c = i;
                    int dist = 2 * (max({a, b, c}) - min({a, b, c}));
                    mini = min(mini, dist);
                }

                prev = last;
                last = i;
            }
        }

        return mini == INT_MAX ? -1 : mini;
    }
};