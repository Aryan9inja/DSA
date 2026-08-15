#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
	int memo[10][2][2];
	string limit_str;
	int target_d;
	
	int solve(int idx, bool tight, bool leading_zero) {
		if (idx == limit_str.length()) {
			return leading_zero ? 0 : 1;
		}
		
		if (memo[idx][tight][leading_zero] != -1) {
			return memo[idx][tight][leading_zero];
		}
		
		int ans = 0;
		int limit = tight ? limit_str[idx]-'0' : 9;
		
		for (int c = 0; c <= limit; c++) {
			if (c == target_d) {
				// EXCEPTION: If we are placing leading zeros and d is 0
				if (target_d == 0 && leading_zero) {
					// Do nothing, let it pass
				} else {
					continue;
				}
			}
			
			bool next_tight = tight && (c == limit);
			bool next_leading_zero = leading_zero && (c == 0);
			
			ans += solve(idx + 1, next_tight, next_leading_zero);
		}
		
		return memo[idx][tight][leading_zero] = ans;
	}
	
	int countWithout(int n, int d) {
		if (n == 0)
			return 0;
		
		limit_str = to_string(n);
		target_d = d;
		
		memset(memo, -1, sizeof(memo));
		
		return solve(0, true, true);
	}
};
