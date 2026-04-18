#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mirrorDistance(int n) {
        auto revDigit = [](int num) {
            int reversed = 0;
            while (num != 0) {
                reversed = reversed * 10 + num % 10;
                num /= 10;
            }
            return reversed;
        };

        return abs(n-revDigit(n));
    }
};