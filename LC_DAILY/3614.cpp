#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();

        long long len = 0;
        vector<long long> lenArr(n);

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (c >= 'a' && c <= 'z')
                len++;
            else if (c == '*' && len >= 1)
                len--;
            else if (c == '#')
                len *= 2;

            lenArr[i] = len;
        }

        if (n == 0 || k >= lenArr[n - 1] || k < 0)
            return '.';

        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];

            if (c >= 'a' && c <= 'z' && k == lenArr[i] - 1) {
                return c;
            }
            else if (c == '#') {
                long long prev_len = lenArr[i] / 2;
                if (prev_len > 0)
                    k = k % prev_len;
            }
            else if (c == '%') {
                k = lenArr[i] - 1 - k;
            }
        }

        return '.';
    }
};