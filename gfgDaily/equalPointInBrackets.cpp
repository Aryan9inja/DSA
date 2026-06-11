#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findIndex(string& s) {
        int n = s.size();
        int openCnt = 0, closeCnt = 0;

        // Count total closing brackets
        for (int i = 0; i < n; i++) {
            if (s[i] == ')')
                closeCnt++;
        }

        for (int i = 0; i <= n; i++) {

            // Equal point found
            if (openCnt == closeCnt)
                return i;

            if (i < n) {

                // Count opening brackets before next index
                if (s[i] == '(')
                    openCnt++;

                // Count closing brackets from next index onward
                if (s[i] == ')')
                    closeCnt--;
            }
        }

        return -1;
    }

};
