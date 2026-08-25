#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& arr) {
        int n = arr.size();

        vector<int> cnt(n + 1, 0);

        for (int a : arr) {
            if (cnt[a - 1]) {
                cnt[a] = cnt[a - 1] + 1;
            }
            else {
                cnt[a] = 1;
            }
        }

        int longest = 0;
        for (int c : cnt) {
            longest = max(longest, c);
        }

        return n - longest;
    }
};
