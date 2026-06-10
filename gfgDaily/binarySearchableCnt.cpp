#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& arr, int l, int r, int lr, int rl) {
        // invalid indexes
        if (l > r)
            return 0;
        int ans = 0;

        // find the middle element of the current array
        int m = (l + r) / 2;

        // if lr < arr[m] and arr[m] < rl,
        // arr[m] is binary searchable
        if (lr < arr[m] && arr[m] < rl)
            ans = 1;

        // find the binary searchable elements
        // to the left of middle element
        int l_ans = solve(arr, l, m - 1, lr, min(rl, arr[m]));

        // find the binary searchable elements
        // to the right of middle element
        int r_ans = solve(arr, m + 1, r, max(lr, arr[m]), rl);

        return ans + l_ans + r_ans;
    }

    int binarySearchable(vector<int>& arr) {
        int n = arr.size();
        return solve(arr, 0, n - 1, -1e6, 1e6);
    }
};
