#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 	int maxSumSubarray(vector<int> &arr) {
    // 		int n = arr.size();

    // 		vector<int> pre(n);
    // 		vector<int> suff(n);

    // 		pre[0] = arr[0];
    // 		for (int i = 1; i < n; i++) {
    // 			pre[i] = max(arr[i], pre[i - 1] + arr[i]);
    // 		}

    // 		suff[n - 1] = arr[n - 1];
    // 		for (int i = n - 2; i >= 0; i--) {
    // 			suff[i] = max(arr[i], suff[i + 1] + arr[i]);
    // 		}

    // 		// Maximum subarray sum without deletion
    // 		int ans = *max_element(pre.begin(), pre.end());

    // 		// Try removing each element
    // 		for (int i = 1; i < n - 1; i++) {
    // 			ans = max(ans, pre[i - 1] + suff[i + 1]);
    // 		}

    // 		return ans;
    // 	}

    int maxSumSubarray(vector<int>& arr) {
        int n = arr.size();

        // noDel -> Maximum subarray sum ending at current index
        //         without deletion
        // oneDel -> Maximum subarray sum ending at current index
        //         with at most one deletion
        int noDel = arr[0];
        int oneDel = 0;

        // Final answer
        int ans = arr[0];

        for (int i = 1; i < n; i++) {
            // Either delete current element
            // OR extend previous deleted subarray
            oneDel = max(noDel, arr[i] + oneDel);

            // Standard Kadane transition
            noDel = max(arr[i], arr[i] + noDel);

            // Update answer
            ans = max(ans, max(noDel, oneDel));
        }

        return ans;
    }
};
