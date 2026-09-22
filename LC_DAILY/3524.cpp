#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0), prev(k, 0);

        for (int& num : nums) {
            vector<long long> curr(k, 0);

            int r = num % k;
            curr[r]++;

            for (int old = 0; old < k; old++) {
                curr[(old * r) % k] += prev[old];
            }

            prev = curr;

            for (int i = 0; i < k; i++) {
                result[i] += prev[i];
            }
        }

        return result;
    }
};