#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void constructLps(vector<int>& pat, vector<int>& lps) {
        // len stores the length of longest
        // prefix which is also a suffix
        // for the previous index
        int len = 0;

        // lps[0] is always 0
        lps[0] = 0;

        int i = 1;
        while (i < pat.size()) {
            // If numbers match, increment
            // the size of lps
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if (len != 0) {
                    // Update len to the previous lps value
                    // to avoid reduntant comparisons
                    len = lps[len - 1];
                }
                else {
                    // If no matching prefix found,
                    // set lps[i] to 0
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    vector<int> search(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();

        vector<int> lps(m);
        vector<int> res;

        constructLps(b, lps);

        // Pointers i and j, for traversing
        // a[] and b[]
        int i = 0;
        int j = 0;

        while (i < n) {
            // If elements match, move
            // both pointers forward
            if (a[i] == b[j]) {
                i++;
                j++;

                // If all elements of b[] are matched
                // store the start index in result
                if (j == m) {
                    res.push_back(i - j);

                    // Use LPS of previous index to
                    // skip unnecessary comparisons
                    j = lps[j - 1];
                }
            }

            // If there is a mismatch
            else {
                // Use lps value of previous index
                // to avoid redundant comparisons
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        return res;
    }
};
