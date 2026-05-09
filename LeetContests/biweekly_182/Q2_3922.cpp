#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        if (n <= 2) return 0;

        int oneCnt = 0;
        for (char c : s) {
            if (c == '1') oneCnt++;
        }

        int mini = oneCnt;

        mini = min(mini, n - oneCnt);

        if (oneCnt > 0) {
            mini = min(mini, oneCnt - 1);
        }

        int cost = (s[0] == '0') + (s[n - 1] == '0');
        int midOneCnt = 0;
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == '1') midOneCnt++;
        }

        mini = min(mini, cost + midOneCnt);

        return mini;
    }
};