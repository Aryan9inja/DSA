#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestSubstring(string& s) {
        int res = INT_MAX;

        // To check 0, 1 and 2
        bool zero = false, one = false, two = false;

        // To store indexes of 0, 1 and 2
        int zeroindex, oneindex, twoindex;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                zero = true;
                zeroindex = i;
            }
            else if (s[i] == '1') {
                one = true;
                oneindex = i;
            }
            else if (s[i] == '2') {
                two = true;
                twoindex = i;
            }

            // Calculating length
            if (zero and one and two)
                res = min(res, max({ zeroindex, oneindex, twoindex }) - min({ zeroindex, oneindex, twoindex }));
        }

        // In case if there is no substring that contains 0,1 and 2
        if (res == INT_MAX)
            return -1;
        return res + 1;
    }
};
