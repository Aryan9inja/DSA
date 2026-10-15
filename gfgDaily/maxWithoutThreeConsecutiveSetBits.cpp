#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValue(int n) {
        int res = n;

        for (int i = 30; i >= 2; --i) {
            if ((res & (1 << i)) && (res & (1 << (i - 1))) && (res & (1 << (i - 2)))) {
                // Clear the lowest bit of the three consecutive set bits.
                res &= ~(1 << (i - 2));
            }
        }

        return res;
    }
};
