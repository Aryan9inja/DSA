#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 	int maxDotProduct(vector<int> &a, vector<int> &b)
    // 	{

    // 		int n = a.size();
    // 		int m = b.size();

    // 		// dp[i][j] stores max dot product for
    // 		// prefix a[0..i-1] and b[0..j-1]
    // 		// Initialize with a large negative value
    // 		vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1e9));
    // 		for (int i = 0; i <= n; i++)
    // 			dp[i][0] = 0;

    // 		// Fill dp table
    // 		for (int i = 1; i <= n; i++)
    // 			{

    // 			for (int j = 1; j <= m; j++)
    // 				{

    // 				// Take current pair
    // 				int take = a[i - 1] * b[j - 1] + dp[i - 1][j - 1];

    // 				// Skip current element of a
    // 				int skip = dp[i - 1][j];

    // 				dp[i][j] = max(take, skip);
    // 			}
    // 		}

    // 		// Return the maximum dot product
    // 		return dp[n][m];
    // 	}

    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int m = a.size();
        int n = b.size();

        vector<int> dp(n + 1, -1e9);
        dp[0] = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = n; j >= 1; j--) {

                // Calculate the maximum dot product at
                // position j by choosing between not
                // including b[j-1] and including b[j-1]
                // Update dp[j] with the maximum value
                dp[j] = max(dp[j], dp[j - 1] + (a[i - 1] * b[j - 1]));
            }
        }

        // Return the maximum dot product
        return dp[n];
    }

};
