// LC 3 -> Longest substring without repeating characters

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int i = 0, j = 0;

        unordered_map<char, int> freq;

        while (j < s.length()) {
            char curr = s[j];
            while (freq[curr] > 0) {
                freq[s[i]]--;
                i++;
            }

            freq[curr]++;
            maxLength = max(maxLength, j - i + 1);

            j++;
        }

        return maxLength;
    }

    int lengthOfLongestSubstringAdv(string s) {
        unordered_map<char, int> lastSeen;

        int maxLength = 0, i = 0;

        for (int j = 0; j < s.length(); j++) {
            if (lastSeen.count(s[j])) {
                i = max(i, lastSeen[s[j]] + 1);
            }

            lastSeen[s[j]] = j;
            maxLength = max(maxLength, j - i + 1);
        }

        return maxLength;
    }
};