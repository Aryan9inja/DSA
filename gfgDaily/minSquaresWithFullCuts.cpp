#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSquares(int n, int m) {
        int res = 0;

        while (n > 0 && m > 0) {
            if (n < m)
                swap(n, m);

            res += n / m;

            n %= m;
        }

        return res;
    }
};
