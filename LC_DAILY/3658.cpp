#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long sumOdd = (long long)n * n;

        long long sumEven = (long long)n * (n + 1);

        return (int)gcd(sumOdd, sumEven);
    }
};