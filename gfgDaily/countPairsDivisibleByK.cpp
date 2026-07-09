#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countKdivPairs(vector<int>& arr, int k) {
        vector<int> freq(k, 0);

        for (const int& a : arr) {
            ++freq[a % k];
        }

        int res = freq[0] * (freq[0] - 1) / 2;

        for (int i = 1; i <= k / 2 && i != (k - i); i++) {
            res += freq[i] * freq[k - i];
        }

        if (k % 2 == 0) {
            res += freq[k / 2] * (freq[k / 2] - 1) / 2;
        }

        return res;
    }
};
