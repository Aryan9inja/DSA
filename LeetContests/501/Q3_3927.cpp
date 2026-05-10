#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        set<int> uniques(nums.begin(), nums.end());
        vector<int> sortedUnique(uniques.begin(), uniques.end());

        long long totalSum = 0;

        for (int num : nums) {
            int best = num;

            for (int div : sortedUnique) {
                if (div >= num) break;

                if (num % div == 0) {
                    best = div;
                    break;
                }
            }
            totalSum += best;
        }

        return totalSum;
    }
};