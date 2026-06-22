#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<pair<int, int>> it; // intervals

        for (int i = 0; i < n; i++) {
            if (lights[i] > 0) {
                int s = max(0, i - lights[i]);
                int e = min(n - 1, i + lights[i]);
                it.push_back({ s, e });
            }
        }

        sort(it.begin(), it.end());

        int maxi = -1;
        int ans = 0;

        for (const auto& i : it) {
            int s = i.first;
            int e = i.second;

            if (s > maxi + 1) {
                int gap = s - maxi - 1;
                ans += (gap + 2) / 3;
            }

            maxi = max(maxi, e);
        }

        if (maxi < n - 1) {
            int gap = n - 1 - maxi;
            ans += (gap + 2) / 3;
        }
        return ans;
    }
};