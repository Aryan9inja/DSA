#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countValidPrefixes(string s) {
        int oneCnt = 0, zeroCnt = 0;
        int ans = 0;
        for (auto& ch : s) {
            if (ch == '1') oneCnt++;
            else zeroCnt++;

            if (oneCnt == zeroCnt) ans++;
            else if (oneCnt == zeroCnt + 1) ans++;
            else if (oneCnt + 1 == zeroCnt) ans++;
        }

        return ans;
    }
};