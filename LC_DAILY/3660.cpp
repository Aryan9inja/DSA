#include<bits/stdc++.h>
using namespace std;

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 'c';
}();

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> pre(n), suf(n), res(n);

        /*
            pre[i] = maximum value in prefix [0...i]

            Why do we need this?

            To know the strongest (largest) value available
            on the LEFT side of a boundary.
        */
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = max(nums[i], pre[i - 1]);
        }

        /*
            suf[i] = minimum value in suffix [i...n-1]

            Why do we need this?

            To know the weakest (smallest) value available
            on the RIGHT side of a boundary.
        */
        suf[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = min(nums[i], suf[i + 1]);
        }

        /*
            Key Observation:

            If:

                pre[i] > suf[i+1]

            then there exists:

                leftValue > rightValue

            across the boundary between i and i+1.

            That means a valid jump exists:

                left -> right

            Once ONE crossing jump exists,
            both sides become part of the same reachable component.

            So we MERGE segments.
        */

        // last segment always reaches its own prefix maximum
        res[n - 1] = pre[n - 1];

        for(int i = n - 2; i >= 0; i--) {

            // boundary can be crossed -> same component
            if(pre[i] > suf[i + 1]) {

                /*
                    Since segments merge,
                    answer becomes same as right side.

                    Connectivity propagates.
                */
                res[i] = res[i + 1];
            }

            // no crossing edge -> start new component
            else {

                /*
                    No way to connect across boundary.

                    Best reachable value inside this segment
                    is simply its prefix maximum.
                */
                res[i] = pre[i];
            }
        }

        return res;
    }
};