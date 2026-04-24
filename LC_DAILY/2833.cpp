#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int lCnt = 0;
        int rCnt = 0;

        for (char c : moves) {
            if (c == 'L')
                lCnt++;
            if (c == 'R')
                rCnt++;
        }

        int ans = 0;
        if (lCnt >= rCnt) {
            lCnt += moves.length() - (lCnt + rCnt);
            ans = lCnt - rCnt;
        } else {
            rCnt += moves.length() - (lCnt + rCnt);
            ans = rCnt - lCnt;
        }

        return ans;
    }
};