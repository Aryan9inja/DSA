#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1 - Keeping track of increasing
    // Or decreasing numbers before and after
    // The current number
    /*
    int bitonic(vector<int> &arr) {
        int n = arr.size();
        if (n == 0)
            return 0;

        // Keeps track of numbers
        // increasing before
        // current number
        vector<int> inc(n);

        // Keeps track of numbers
        // decreasing after
        // current number
        vector<int> dec(n);

        inc[0] = 1;
        dec[n - 1] = 1;

        for (int i = 1; i<n; i++) {
            inc[i] = (arr[i] >= arr[i - 1]) ? inc[i - 1]+1 : 1;
        }

        for (int i = n - 2; i >= 0; i--) {
            dec[i] = (arr[i] >= arr[i + 1]) ? dec[i + 1]+1 : 1;
        }

        int maxi = inc[0] + dec[0] - 1;
        for (int i = 1; i<n; i++) {
            maxi = max(maxi, inc[i]+dec[i]-1);
        }

        return maxi;
    }
    */

    // Approach 2 - Keeping track of
    // When a peak will start
    // While descending
    // Think every point as potential
    // Peak start
    int bitonic(vector<int>& arr) {
        int n = arr.size();
        if (n == 0)
            return 0;

        int start = 0;
        int nextStart = 0;
        int j = 0;

        int maxi = 1;

        while (j < n - 1) {
            while (j < n - 1 && arr[j] <= arr[j + 1]) {
                j++;
            }

            while (j < n - 1 && arr[j] >= arr[j + 1]) {
                if (j<n - 1 && arr[j]>arr[j + 1]) {
                    nextStart = j + 1;
                }

                j++;
            }

            maxi = max(maxi, j - start + 1);

            start = nextStart;
        }

        return maxi;
    }
};
