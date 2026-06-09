#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxi = -1e16;
        long long mini = 1e16;

        for (auto& n : nums) {
            maxi = max(maxi, (long long)n);
            mini = min(mini, (long long)n);
        }

        return k * (maxi - mini);
    }
};