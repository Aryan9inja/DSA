#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wifiRange(string& s, int x) {
        int n = s.length();

        int maxReach = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (maxReach < i - x - 1) {
                    return false;
                }
                maxReach = max(maxReach, x + i);
            }
        }

        return maxReach >= n - 1;
    }
};