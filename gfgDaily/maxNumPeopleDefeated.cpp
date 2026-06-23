#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sum(int h) {
        return h * (h + 1) * (2 * h + 1) / 6;
    }

    int maxPeopleDefeated(int p) {
        int low = 0, high = 1000;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (sum(mid) <= p) {
                ans = mid;
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
