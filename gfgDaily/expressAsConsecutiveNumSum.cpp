#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSumOfConsecutive(int n) {
        if (n == 1)
            return false;

        if ((n & (n - 1)) == 0) {
            return false;
        }

        return true;
    }
};
