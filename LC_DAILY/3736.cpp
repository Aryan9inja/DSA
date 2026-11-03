#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = 0;
        for (int& n : nums) {
            maxi = max(maxi, n);
        }

        int res = 0;
        for (int& n : nums) {
            res += (maxi - n);
        }

        return res;
    }
};