#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini = 1001;
        int maxi = 0;

        for (int& n : nums) {
            mini = min(mini, n);
            maxi = max(maxi, n);
        }

        return gcd(mini, maxi);
    }
};