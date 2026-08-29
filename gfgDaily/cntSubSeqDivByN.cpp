#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
	public:
	/*
	int sz;
	vector<vector<vector<int>> > dp;
	
	int solve(string& s, int n, int idx, int rem, bool started) {
		if (idx == sz) {
			return (started && rem == 0) ? 1 : 0;
		}
		
		if (dp[idx][rem][started] != -1) {
			return dp[idx][rem][started];
		}
		
		int ans = 0;
		
		// Not take
		ans = (ans + solve(s, n, idx + 1, rem, started))%MOD;
		
		int dig = s[idx] - '0';
		int newRem;
		if (!started) {
			newRem = dig%n;
		}
		else {
			newRem = (rem*10 + dig)%n;
		}
		
		// Take
		ans = (ans + solve(s, n, idx + 1, newRem, true))%MOD;
		
		return ans;
	}
	*/
	
	int countSubsequences(string& s, int n) {
		/*
		sz = s.length();
		
		// idx, remainder, started
		dp.assign(sz, vector<vector<int>> (n, vector<int>(2, -1)));
		
		return solve(s, n, 0, 0, false);
		*/
		
		/*
		int sz = s.length();
		
		vector<vector<vector<int>> > dp(sz + 1, vector<vector<int>> (n, vector<int>(2, 0)));
		
		for (int rem = 0; rem<n; rem++) {
			dp[sz][rem][0] = 0;
			dp[sz][rem][1] = (rem == 0);
		}
		
		for (int idx = sz - 1; idx >= 0; idx--) {
			int dig = s[idx] - '0';
			for (int rem = 0; rem<n; rem++) {
				for (int started = 0; started <= 1; started++) {
					int ans = 0;
					
					// Not take
					ans = (ans + dp[idx + 1][rem][started])%MOD;
					
					int newRem;
					if (!started) {
						newRem = dig%n;
					}
					else {
						newRem = (rem*10 + dig)%n;
					}
					
					// Take
					ans = (ans + dp[idx + 1][newRem][1])%MOD;
					
					dp[idx][rem][started] = ans;
				}
			}
		}
		
		return dp[0][0][0];
		*/
		
		int sz = s.length();
		
		vector<int> dp(n, 0);
		
		for (char c : s) {
			int dig = c - '0';
			
			vector<int> ndp = dp;
			
			// Start a new subsequence with just this digit
			ndp[dig % n] = (ndp[dig % n] + 1) % MOD;
			
			// Append digit to every existing subsequence
			for (int rem = 0; rem < n; rem++) {
				int newRem = (rem * 10 + dig) % n;
				
				ndp[newRem] = (ndp[newRem] + dp[rem]) % MOD;
			}
			
			dp.swap(ndp);
		}
		
		return dp[0];
	}
};
