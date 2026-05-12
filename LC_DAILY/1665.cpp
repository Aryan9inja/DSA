#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool sorter(const vector<int>& a, const vector<int>& b) {
        int diff1 = a[1] - a[0];
        int diff2 = b[1] - b[0];

        if (diff1 > diff2) {
            return true;
        }
        else if (diff1 == diff2) {
            return a[1] > b[1];
        }
        return false;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), sorter);

        int ans = 0;
        int curr = 0;
        for (const auto& t : tasks) {
            if (curr < t[1]) {
                ans += (t[1] - curr);
                curr = t[1];
            }
            curr -= t[0];
        }

        return ans;
    }
};