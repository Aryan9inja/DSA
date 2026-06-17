#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(int n) {
        if (n == 2 || n == 3) {
            return n - 1;
        }

        int product = 1;

        // Keep cutting parts of length 3
        // while remaining length is greater than 4
        while (n > 4) {
            product *= 3;
            // Reduce rope length
            n -= 3;
        }

        // Multiply remaining rope length
        return product * n;
    }
};
