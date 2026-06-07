// Problem - Count numbers from 1 to N whose digit sum = x
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    string s;
    int target;

    int solve(int pos, int sum, bool tight) {
        if (pos == s.size()) {
            return sum == target;
        }

        int limit = tight ? s[pos] - '0' : 9;

        int ans = 0;

        for (int d = 0; d <= limit; d++) {
            ans += solve(
                pos + 1,
                sum + d,
                tight && (d == limit)
            );
        }

        return ans;
    }

public:
    int countSumNumbers(int N, int x) {
        s = to_string(N);
        target = x;
        return solve(0, 0, true);
    }
};

int main() {
    int N = INT_MAX, x = 10;
    Solution sol;
    cout << sol.countSumNumbers(N, x) << endl;
    return 0;
}