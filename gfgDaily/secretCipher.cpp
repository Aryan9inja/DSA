#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void computeLPS(string& s, vector<int>& lps) {
        int n = s.size();

        lps[0] = 0;

        for (int i = 1; i < n; i++) {
            int len = lps[i - 1];

            // Find the longest prefix which i s also a suffix
            while (len > 0 && s[i] != s[len]) {
                len = lps[len - 1];
            }

            if (s[i] == s[len]) {
                len++;
            }

            lps[i] = len;
        }
    }

    string compress(string& s) {
        int n = s.size();

        // Stores the LPS value for every prefix
        vector<int> lps(n);

        computeLPS(s, lps);

        stack<char> st;

        // Traverse the prefixes from right to left
        for (int i = n - 1; i > 0; i--) {
            int len = i + 1;

            // Odd-length prefixes cannot be divided into two equal halves
            if (len % 2 == 1) {
                st.push(s[i]);
                continue;
            }

            int longestPrefixSuffix = lps[i];
            bool canCompress = false;

            // Length of the smallest repeating block
            int blockLength = len - longestPrefixSuffix;

            // Check if the prefix is made up of an even number
            // of repetitions of its smallest repeating block
            if (longestPrefixSuffix * 2 >= len && len % blockLength == 0 && (len / blockLength) % 2 == 0) {
                canCompress = true;
            }

            if (canCompress) {
                // Replace the second half with '*'
                st.push('*');

                // Continue processing only the first half
                i = (len / 2);
            }
            else {
                st.push(s[i]);
            }
        }

        string ans;

        // The first character is always present
        ans.push_back(s[0]);

        // Reverse the constructed answer
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
