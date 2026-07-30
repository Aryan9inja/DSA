#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0;
        int mul = 1;

        while (n > 0) {
            int temp = min(n, 8);
            ans += temp * mul;
            n -= temp;
            mul++;
        }

        return ans;
    }
};