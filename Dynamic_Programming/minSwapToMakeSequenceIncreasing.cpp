/*
Step 1 = Add -1 in begining of both arrays
Step 2 = Swap and no swap based on condition of strictly increasing
The problem statement states:
The test cases are generated so that the given input always makes it possible.
So, no need considering that swap would not make sense
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int recursive(vector<int>& nums1, vector<int>& nums2, int idx,
        bool swapped) {
        if (idx == nums1.size())
            return 0;

        int ans = INT_MAX;

        int prev1 = nums1[idx - 1];
        int prev2 = nums2[idx - 1];

        if (swapped)
            swap(prev1, prev2);

        // no swap
        if (nums1[idx] > prev1 && nums2[idx] > prev2)
            ans = recursive(nums1, nums2, idx + 1, false);

        // swap
        if (nums1[idx] > prev2 && nums2[idx] > prev1)
            ans = min(ans, 1 + recursive(nums1, nums2, idx + 1, true));

        return ans;
    }

    int memoization(vector<int>& nums1, vector<int>& nums2, int idx,
        bool swapped, vector<vector<int>>& dp) {
        if (idx == nums1.size())
            return 0;

        if (dp[idx][swapped] != -1)
            return dp[idx][swapped];

        int ans = INT_MAX;

        int prev1 = nums1[idx - 1];
        int prev2 = nums2[idx - 1];

        if (swapped)
            swap(prev1, prev2);

        // no swap
        if (nums1[idx] > prev1 && nums2[idx] > prev2)
            ans = memoization(nums1, nums2, idx + 1, false, dp);

        // swap
        if (nums1[idx] > prev2 && nums2[idx] > prev1)
            ans = min(ans, 1 + memoization(nums1, nums2, idx + 1, true, dp));

        return dp[idx][swapped] = ans;
    }

    int tabulation(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int idx = n - 1; idx >= 1; idx--) {
            for (int swapped = 1; swapped >= 0; swapped--) {
                int ans = INT_MAX;

                int prev1 = nums1[idx - 1];
                int prev2 = nums2[idx - 1];

                if (swapped)
                    swap(prev1, prev2);

                // no swap
                if (nums1[idx] > prev1 && nums2[idx] > prev2)
                    ans = dp[idx + 1][0];

                // swap
                if (nums1[idx] > prev2 && nums2[idx] > prev1)
                    ans = min(ans, 1 + dp[idx + 1][1]);

                dp[idx][swapped] = ans;
            }
        }
        return dp[1][0];
    }

    int spaceOptimal(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        int swaper = 0;
        int noSwap = 0;
        int currSwap = 0;
        int currNoSwap = 0;

        for (int idx = n - 1; idx >= 1; idx--) {
            for (int swapped = 1; swapped >= 0; swapped--) {
                int ans = INT_MAX;

                int prev1 = nums1[idx - 1];
                int prev2 = nums2[idx - 1];

                if (swapped)
                    swap(prev1, prev2);

                // no swap
                if (nums1[idx] > prev1 && nums2[idx] > prev2)
                    ans = noSwap;

                // swap
                if (nums1[idx] > prev2 && nums2[idx] > prev1)
                    ans = min(ans, 1 + swaper);

                if (swapped)
                    currSwap = ans;
                else
                    currNoSwap = ans;
            }
            swaper = currSwap;
            noSwap = currNoSwap;
        }
        return min(swaper, noSwap);
    }

public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        bool swapped = false;
        // return recursive(nums1, nums2, 1, swapped);

        // int n = nums1.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return memoization(nums1, nums2, 1, swapped, dp);

        // return tabulation(nums1, nums2);

        return spaceOptimal(nums1, nums2);
    }
};