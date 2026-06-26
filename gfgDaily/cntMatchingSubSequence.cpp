#include<bits/stdc++.h>
using namespace std;

static const int MOD = 1e9 + 7;

class Solution {
	vector<vector<int>> dp;
	public:
	int solve(string& s1, string& s2, int idx1, int idx2) {
		if (idx2 == s2.size()) {
			return 1;
		}
		
		if (idx1 == s1.size()) {
			return 0;
		}
		
		if (dp[idx1][idx2] != -1)
			return dp[idx1][idx2];
		
		long long ans = solve(s1, s2, idx1 + 1, idx2);
		
		if (s1[idx1] == s2[idx2]) {
			ans += solve(s1, s2, idx1 + 1, idx2 + 1);
		}
		
		return dp[idx1][idx2] = ans % MOD;
	}
	
	int countWays(string &s1, string &s2) {
		// dp.assign(s1.size()+1, vector<int>(s2.size()+1, -1));
		// return solve(s1, s2, 0, 0);
		
				int n = s1.length(), m = s2.length();
		
		// 		dp.assign(n + 1, vector<int>(m + 1, 0));
		
		// 		for (int i = 0; i <= m; i++)
		// 			dp[0][i] = 0;
		// 		for (int i = 0; i <= n; i++)
		// 			dp[i][0] = 1;
		
		// 		for (int i = 1; i <= n; i++) {
		// 			for (int j = 1; j <= m; j++) {
		// 				if (s1[i - 1] == s2[j - 1]) {
		// 					dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
		// 				}
		// 				else {
		// 					dp[i][j] = dp[i - 1][j] % MOD;
		// 				}
		// 			}
		// 		}
		
		// 		return dp[n][m] % MOD
		
		vector<int> dpS(m + 1, 0);
		
		// Empty string can always be formed
		dpS[0] = 1;
		
		for (int i = 1; i <= n; i++)
			{
			
			// Traverse from right to left
			for (int j = m; j >= 1; j--)
				{
				
				// If current characters match,
				// include or exclude current character
				if (s1[i - 1] == s2[j - 1])
					{
					dpS[j] = (dpS[j] + dpS[j - 1]) % MOD;
				}
			}
		}
		
		return dpS[m];
	}
};
