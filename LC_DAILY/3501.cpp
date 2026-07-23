#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int totalOnes = ranges::count(s, '1');

        // ------------------------------------------------------------
        // Step 1: Extract every maximal block of consecutive zeros.
        //
        // zeroStart[i] = starting index of i-th zero block
        // zeroEnd[i]   = ending index of i-th zero block
        // ------------------------------------------------------------
        vector<int> zeroStart;
        vector<int> zeroEnd;

        for (int i = 0; i < n;) {
            if (s[i] == '1') {
                i++;
                continue;
            }

            int start = i;
            while (i < n && s[i] == '0')
                i++;

            zeroStart.push_back(start);
            zeroEnd.push_back(i - 1);
        }

        int zeroBlockCount = zeroStart.size();

        // ------------------------------------------------------------
        // Valley i consists of:
        //      zero block i
        //      one block
        //      zero block i+1
        //
        // valleyGain[i] = total zeros gained if this valley is traded.
        // ------------------------------------------------------------
        vector<int> valleyGain;

        for (int i = 0; i + 1 < zeroBlockCount; i++) {
            int leftSize = zeroEnd[i] - zeroStart[i] + 1;
            int rightSize = zeroEnd[i + 1] - zeroStart[i + 1] + 1;

            valleyGain.push_back(leftSize + rightSize);
        }

        // ------------------------------------------------------------
        // Sparse Table for Range Maximum Query over valleyGain[]
        // ------------------------------------------------------------
        vector<vector<int>> sparseTable;
        sparseTable.push_back(valleyGain);

        int offset = 1;

        while (offset * 2 <= (int)valleyGain.size()) {
            vector<int> level;

            for (int i = 0; i + offset < (int)sparseTable.back().size(); i++) {
                level.push_back(max(
                    sparseTable.back()[i],
                    sparseTable.back()[i + offset]
                ));
            }

            sparseTable.push_back(move(level));
            offset *= 2;
        }

        auto rangeMaximum = [&](int left, int right) {
            int len = right - left + 1;
            int level = bit_width((unsigned)len) - 1;

            return max(
                sparseTable[level][left],
                sparseTable[level][right - (1 << level) + 1]
            );
            };

        // ------------------------------------------------------------
        // Returns the gain of valley 'id' after clipping it to
        // query interval [left, right].
        //
        // A query may start/end inside the valley, reducing the
        // usable zero lengths.
        // ------------------------------------------------------------
        auto clippedGain = [&](int id, int left, int right) {

            int lostOnLeft =
                max(0, left - zeroStart[id]);

            int lostOnRight =
                max(0, zeroEnd[id + 1] - right);

            return valleyGain[id] - lostOnLeft - lostOnRight;
            };

        auto bestGainInsideWindow = [&](int left, int right) {

            if (zeroBlockCount < 2)
                return 0;

            // First valley whose left zero block intersects the query.
            int firstValley =
                ranges::lower_bound(zeroEnd, left) - zeroEnd.begin();

            // Last valley whose right zero block intersects the query.
            int lastValley =
                ranges::upper_bound(zeroStart, right) - zeroStart.begin() - 2;

            if (firstValley > lastValley)
                return 0;

            int answer = 0;

            // Boundary valleys may be partially clipped.
            answer = max(answer, clippedGain(firstValley, left, right));
            answer = max(answer, clippedGain(lastValley, left, right));

            // Interior valleys lie completely inside the query.
            if (lastValley - firstValley >= 2) {
                answer = max(
                    answer,
                    rangeMaximum(firstValley + 1, lastValley - 1)
                );
            }

            return answer;
            };

        vector<int> result;
        result.reserve(queries.size());

        for (const auto& query : queries) {
            result.push_back(
                totalOnes + bestGainInsideWindow(query[0], query[1])
            );
        }

        return result;
    }
};