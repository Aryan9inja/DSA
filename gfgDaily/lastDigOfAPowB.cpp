#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMod(string& b, int d) {
        int mod = 0;

        for (int i = 0; i < b.size(); i++) {
            mod = (mod * 10 + b[i] - '0') % d;
        }

        return mod;
    }

    int getLastDigit(string& a, string& b) {
        int n = a.size(), m = b.size();

        if (m == 1 && b[0] == '0') {
            return 1;
        }

        if (n == 1 && a[0] == '0') {
            return 0;
        }

        int modExp = getMod(b, 4);
        int expo = modExp == 0 ? 4 : modExp;
        int base = a[n - 1] - '0';

        int res = pow(base, expo);

        return res % 10;
    }
};
