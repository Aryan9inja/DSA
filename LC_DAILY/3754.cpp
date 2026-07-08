#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sumAndMultiply(int n) {
        int x = 0;
        int sum = 0;

        int y = 0;
        while (n > 0) {
            int dig = n % 10;
            n /= 10;

            if (dig != 0) {
                x += dig * pow(10, y);
                y++;
            }

            sum += dig;
        }

        return (long long)x * sum;
    }
};