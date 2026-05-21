#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBitSet(int n) {
        if (n == 0) return false;
        while (n) {
            if (!(n & 1)) return false;
            n >>= 1;
        }
        return true;
    }
};