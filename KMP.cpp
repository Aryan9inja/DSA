// The KMP (Knuth–Morris–Pratt) algorithm is a string matching algorithm
// used to find a pattern inside a text efficiently.
// Instead of restarting comparisons from scratch after a mismatch,
// KMP uses information from the pattern itself to skip unnecessary checks.
// It works in: O(n+m)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> buildLPS(string pattern) {
        int m = pattern.size();
        vector<int> lps(m, 0);

        int len = 0;
        int i = 1;

        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if (len != 0) {
                    len = lps[len - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    int strStr(string text, string pattern) {
        int n = text.size();
        int m = pattern.size();

        vector<int> lps = buildLPS(pattern);

        int i = 0;
        int j = 0;

        while (i < n) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            }

            if (j == m) {
                return i - j;
            }
            else if (i < n && text[i] != pattern[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                }
                else {
                    i++;
                }
            }
        }

        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution S;
    vector<int> lps = S.buildLPS("ababd");
    for(const int &n : lps) cout<<n<<" ";

    cout<<endl;

    cout<<S.strStr("ababcabcabababd", "ababd")<<endl;

    return 0;
}