#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        if (s.length() > t.length()) return false;

        int n = s.length(), m = t.length();

        vector<int> left(n, m);
        int tIdx = 0;
        for (int i = 0; i < n; i++) {
            while (tIdx < m && t[tIdx] != s[i]) {
                tIdx++;
            }
            if (tIdx < m) {
                left[i] = tIdx;
                tIdx++;
            }
            else {
                break;
            }
        }

        if (left[n - 1] < m) return true;

        vector<int> right(n, -1);
        tIdx = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (tIdx >= 0 && t[tIdx] != s[i]) {
                tIdx--;
            }
            if (tIdx >= 0) {
                right[i] = tIdx;
                tIdx--;
            }
            else {
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            int l = (i == 0) ? -1 : left[i - 1];
            int r = (i == n - 1) ? m : right[i + 1];

            if (l < r - 1) return true;
        }

        return false;
    }
};