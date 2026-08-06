#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digProduct(int x) {
        int p = 1;
        while (x > 0) {
            p = p * (x % 10);
            x /= 10;
        }

        return p;
    }

    int smallestNumber(int n, int t) {
        while (true) {
            int d = digProduct(n);
            if (d % t == 0) break;

            n++;
        }

        return n;
    }
};