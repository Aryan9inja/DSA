#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26, -1), last(26, -1);

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1)
                first[c] = i;
            last[c] = i;
        }

        // intervals - {end, start}
        vector<pair<int, int>> intervals;

        for (int i = 0; i < 26; i++) {
            if (first[i] == -1)
                continue;

            int start = first[i];
            int end = last[i];
            bool valid = true;

            for (int i = start; i <= end; i++) {
                int c = s[i] - 'a';
                if (first[c] < start) {
                    // invalid
                    valid = false;
                    break;
                }
                end = max(end, last[c]);
            }

            if (valid) {
                intervals.push_back({ end, start });
            }
        }

        sort(intervals.begin(), intervals.end());

        vector<string> result;
        int prevEnd = -1;

        for (const auto& [end, start] : intervals) {
            if (start > prevEnd) {
                result.push_back(s.substr(start, end - start + 1));
                prevEnd = end;
            }
        }

        return result;
    }
};