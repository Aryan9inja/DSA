#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int ones = 0;
        int i = 0;

        auto compareSubstrings = [](const string& s, int a, int b, int c,
            int d) {
                int len = b - a + 1;
                for (int k = 0; k < len; k++) {
                    if (s[a + k] < s[c + k])
                        return -1;
                    if (s[a + k] > s[c + k])
                        return 1;
                }
                return 0;
            };

        int bestStart = -1;
        int bestEnd = -1;
        int minLen = n + 1;

        for (int j = 0; j < n; j++) {
            if (s[j] == '1')
                ones++;

            while (s[i] == '0' || ones > k) {
                if (s[i] == '1')
                    ones--;
                i++;
            }

            if (ones != k)
                continue;

            int currentLen = j - i + 1;

            if (currentLen < minLen) {
                minLen = currentLen;
                bestStart = i;
                bestEnd = j;
            }
            else if (currentLen == minLen) {
                int cmpResult = compareSubstrings(s, i, j, bestStart, bestEnd);
                if (cmpResult < 0) {
                    bestStart = i;
                    bestEnd = j;
                }
            }
        }

        if (bestStart == -1)
            return "";
        return s.substr(bestStart, minLen);
    }
};