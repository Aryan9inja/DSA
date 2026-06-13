#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            int d = n % 10;
            n /= 10;
            sum += d;
        }
        return sum;
    }

    int squareSum(int n) {
        int sum = 0;
        while (n > 0) {
            int d = n % 10;
            n /= 10;
            sum += (d * d);
        }
        return sum;
    }

    bool checkGoodInteger(int n) {
        return (squareSum(n) - digitSum(n) >= 50);
    }
};