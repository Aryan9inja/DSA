#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digitFrequencyScore(int n) {
        int freq[10] = { 0 };
        int ans = 0;
        while (n > 0) {
            int d = n % 10;
            freq[d]++;
            n = n / 10;
        }

        for (int i = 0; i < 10; i++) {
            ans += i * freq[i];
        }
        return ans;
    }
};