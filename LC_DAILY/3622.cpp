#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int productAndSumsSum(int n) {
        int product = 1;
        int sum = 0;

        while (n > 0) {
            int dig = n % 10;
            product *= dig;
            sum += dig;
            n /= 10;
        }

        return product + sum;
    }

    bool checkDivisibility(int n) {
        int d = productAndSumsSum(n);

        if (n % d == 0) return true;

        return false;
    }
};