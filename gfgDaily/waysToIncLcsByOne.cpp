#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToIncreaseLCSBy1(string& s1, string& s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        int M = 26;

        // Fill positions of each character in vector
        vector<vector<int>> position(M);

        for (int i = 1; i <= n2; i++)
            position[s2[i - 1] - 'a'].push_back(i);

        // DP tables
        vector<vector<int>> lcsl(n1 + 2, vector<int>(n2 + 2, 0));
        vector<vector<int>> lcsr(n1 + 2, vector<int>(n2 + 2, 0));

        // Filling LCS array for prefix substrings
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s1[i - 1] == s2[j - 1])
                    lcsl[i][j] = 1 + lcsl[i - 1][j - 1];
                else
                    lcsl[i][j] = max(lcsl[i - 1][j], lcsl[i][j - 1]);
            }
        }

        // Filling LCS array for suffix substrings
        for (int i = n1; i >= 1; i--) {
            for (int j = n2; j >= 1; j--) {
                if (s1[i - 1] == s2[j - 1])
                    lcsr[i][j] = 1 + lcsr[i + 1][j + 1];
                else
                    lcsr[i][j] = max(lcsr[i + 1][j], lcsr[i][j + 1]);
            }
        }

        int ways = 0;
        int baseLCS = lcsl[n1][n2];

        // Looping for all possible insertion positions in first string
        for (int i = 0; i <= n1; i++) {

            // Trying all possible lowercase characters
            for (char c = 'a'; c <= 'z'; c++) {

                vector<int>& posList = position[c - 'a'];

                // Now for each character, loop over same character positions in second string
                for (int j = 0; j < (int)posList.size(); j++) {
                    int p = posList[j];

                    // If both, left and right substrings make total LCS then increase result by 1
                    if (lcsl[i][p - 1] + lcsr[i + 1][p + 1] == baseLCS) {
                        ways++;
                        break;
                    }
                }
            }
        }

        return ways;
    }
};
