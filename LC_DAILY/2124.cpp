#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkString(string s) {
        int lastA = -1;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == 'a') {
                if (i != lastA + 1) {
                    return false;
                }
                lastA = i;
            }
        }

        return true;
    }
};