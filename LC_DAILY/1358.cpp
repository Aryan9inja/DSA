#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int freq[3] = { 0 };

        int l = 0;
        int ans = 0;

        for (int r = 0; r < s.size(); r++) {
            freq[s[r] - 'a']++;

            while (freq[0] && freq[1] && freq[2]) {
                ans += s.size() - r;
                freq[s[l] - 'a']--;
                l++;
            }
        }

        return ans;
    }
};