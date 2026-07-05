#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getDigitRange(int num) {
        int maxi = -1;
        int mini = 10;

        while (num > 0) {
            int dig = num % 10;

            maxi = max(maxi, dig);
            mini = min(mini, dig);

            num /= 10;
        }

        return maxi - mini;
    }

    int maxDigitRange(vector<int>& nums) {
        int ans = 0;
        int maxRange = -1;
        for (const int& num : nums) {
            int range = getDigitRange(num);

            if (range == maxRange) ans += num;
            else if (range > maxRange) {
                maxRange = range;
                ans = num;
            }
        }

        return ans;
    }
};