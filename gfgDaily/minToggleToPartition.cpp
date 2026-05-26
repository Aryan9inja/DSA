#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minToggle(vector<int>& arr) {
        // 		int n = arr.size();
        // 		int zero[n + 1];
        // 		zero[0] = 0;

        // 		// Fill entries in zero[] such that zero[i]
        // 		// stores count of zeroes to the left of i
        // 		for (int i = 1; i <= n; ++i)
        // 			{
        // 			// If zero found update zero[] array
        // 			if (arr[i - 1] == 0)
        // 				zero[i] = zero[i - 1] + 1;
        // 			else
        // 				zero[i] = zero[i - 1];
        // 		}

        // 		// Finding the minimum toggle required from
        // 		// every index(0 to n-1)
        // 		int ans = n;
        // 		for (int i = 0; i <= n; ++i)
        // 			ans = min(ans, i - zero[i] + zero[n] - zero[i]);

        // 		return ans;

        int oneCount = 0;

        // Minimum toggles required
        int toggle = 0;

        for (int x : arr) {
            // If current element is 1
            if (x == 1) {
                oneCount++;
            }
            else {
                // Two choices:
                // 1. Toggle current 0 to 1  -> toggle + 1
                // 2. Toggle all previous 1s to 0 -> oneCount
                toggle = min(toggle + 1, oneCount);
            }
        }

        return toggle;
    }
};
