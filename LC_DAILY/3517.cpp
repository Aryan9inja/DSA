#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    string smallestPalindrome(string s) {
        int n = s.length();
        int mid = n / 2;

        if (n > 1) {
            sort(s.begin(), s.begin() + mid);

            if (n & 1) {
                sort(s.begin() + mid + 1, s.end(), greater<char>());
            } else {
                sort(s.begin() + mid, s.end(), greater<char>());
            }
        }

        return s;
    }
    */

    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        int n = s.size();
        string ans(n, ' ');

        int left = 0, right = n - 1;

        for (int i = 0; i < 26; i++) {
            while (freq[i] >= 2) {
                ans[left++] = char('a' + i);
                ans[right--] = char('a' + i);
                freq[i] -= 2;
            }

            if (freq[i] == 1) {
                ans[s.size() / 2] = char('a' + i);
            }
        }

        return ans;
    }
};