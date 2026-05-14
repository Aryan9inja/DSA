#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        const int n = nums.size() - 1;
        if (n == 0) return 0;
        int freq[n + 1];
        memset(freq, 0, sizeof(freq));
        for (int x : nums) {
            if (x > n) return 0;
            if (++freq[x] == 2) {
                if (x != n) return 0;
            }
        }
        return freq[n] == 2;
    }
};