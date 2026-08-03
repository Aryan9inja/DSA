#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        sort(planks.begin(), planks.end());

        int n = planks.size();

        unordered_map<int, int> singles;
        unordered_map<long long, int> pairs;

        for (int i = 0; i < n; i++) {
            int currPlank = planks[i];
            singles[currPlank]++;

            for (int j = i + 1; j < n; j++) {
                int sec = planks[j];
                long long sum = (long long)currPlank + sec;
                pairs[sum]++;
            }
        }

        vector<long long> options;
        for (const auto& [val, cnt] : singles) {
            options.push_back(val);
        }
        for (const auto& [val, cnt] : pairs) {
            options.push_back(val);
        }

        sort(options.begin(), options.end());
        options.erase(unique(options.begin(), options.end()), options.end());

        int ans = 1;

        for (long long height : options) {
            int s = singles.count(height) ? singles[height] : 0;
            int p = pairs.count(height) ? pairs[height] : 0;

            if (s + p <= ans) continue;

            int currWidth = s;

            int l = 0;
            int r = n - 1;

            while (r >= 0 && planks[r] >= height) {
                r--;
            }

            while (l < r) {
                long long sum = (long long)planks[r] + planks[l];
                if (sum == height) {
                    currWidth++;
                    l++;
                    r--;
                }
                else if (sum < height) {
                    l++;
                }
                else {
                    r--;
                }
            }

            ans = max(ans, currWidth);
        }

        return ans;
    }
};