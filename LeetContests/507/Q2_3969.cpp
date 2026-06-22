#include<bits/stdc++.h>
using namespace std;

class Solution {
    int getFirst(long long k) {
        if (k < 10) return k;

        while (k >= 10) {
            k /= 10;
        }

        return k;
    }

public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            long long sum = nums[i];

            for (int j = i; j < nums.size(); j++) {
                if (i != j) {
                    sum += nums[j];
                }

                int last = sum % 10;
                if (last != x) continue;

                int first = getFirst(sum);
                if (first != x) continue;

                cnt++;
            }
        }

        return cnt;
    }
};