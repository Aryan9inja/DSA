#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [](vector<int>& a, vector<int>& b) {
                if (a[0] == b[0]) {
                    return a[1] > b[1];
                }
                return a[0] < b[0];
            });

        int maxEnd = -1;
        int ans = 0;
        for (const auto& i : intervals) {
            if (maxEnd == -1) {
                maxEnd = i[1];
            }
            else if (i[0] <= maxEnd && i[1] <= maxEnd) {
                continue;
            }
            else {
                maxEnd = i[1];
            }
            ans++;
        }

        return ans;
    }
};