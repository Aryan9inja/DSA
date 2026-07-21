#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIndexDifference(string& s) {
        int n = s.size();

        vector<int> best(26, -1);

        int ans = -1;

        for (int i = n - 1; i >= 0; i--) {
            int farthest = i;

            // Jump to the next alphabet
            // character if it is reachable
            if (s[i] != 'z' && best[s[i] - 'a' + 1] != -1) {
                farthest = best[s[i] - 'a' + 1];
            }
            best[s[i] - 'a'] = max(best[s[i] - 'a'], farthest);

            // Only 'a' can be a starting point
            if (s[i] == 'a') {
                ans = max(ans, farthest - i);
            }
        }
        return ans;
    }
};
