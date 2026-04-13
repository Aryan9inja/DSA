#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> required;
        for(char c : t) required[c]++;

        unordered_map<char, int> window;

        int requiredCount = required.size();
        int formed = 0;

        int i = 0;
        int minLen = INT_MAX;
        int start = 0;

        for(int j = 0; j < s.length(); j++) {
            char c = s[j];
            window[c]++;

            if(required.count(c) && window[c] == required[c]) {
                formed++;
            }

            // shrink window
            while(formed == requiredCount) {
                if(j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }

                char leftChar = s[i];
                window[leftChar]--;

                if(required.count(leftChar) && window[leftChar] < required[leftChar]) {
                    formed--;
                }

                i++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};