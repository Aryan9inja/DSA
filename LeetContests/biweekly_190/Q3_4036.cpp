#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> res;
        res.reserve(nums.size());

        int zNumber = 1 << 25;

        for (int x : nums) {
            string s = "";

            int zS = x / zNumber;
            s.append(zS, 'z');
            x %= zNumber;

            for (int i = 24; i >= 0; i--) {
                if ((x >> i) & 1) {
                    s.push_back('a' + i);
                }
            }
            res.push_back(s);
        }

        return res;
    }
};