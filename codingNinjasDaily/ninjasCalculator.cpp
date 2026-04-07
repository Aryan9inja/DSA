#include <bits/stdc++.h> 
using namespace std;

string toBinaryCalculator(double num) {
    if (num <= 0 || num >= 1) return "ERROR";

    string ans = "0.";

    while (num > 0) {
        if (ans.length() > 34) return "ERROR";

        num *= 2;

        if (num >= 1) {
            ans += '1';
            num -= 1;
        }
        else {
            ans += '0';
        }
    }
    return ans;
}
