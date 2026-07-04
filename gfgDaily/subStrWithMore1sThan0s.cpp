#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstring(string s) {
        int n = s.size();

        // balanceShift is used so that negative balances become valid indices.
        // Actual balance = storedBalance - balanceShift.
        int balanceShift = n;

        // currentBalance stores the shifted prefix balance.
        // Initially, prefix sum = 0.
        int currentBalance = balanceShift;

        // balanceFrequency[b] = number of future prefix sums having shifted balance b.
        vector<int> balanceFrequency(2 * n + 5, 0);

        // invalidPrefixes = number of future prefix sums
        // whose balance <= currentBalance.
        //
        // These correspond to invalid substring endings because
        // pref[r] <= pref[l-1].
        int invalidPrefixes = 0;

        int answer = 0;

        /*------------------------------------------------------------
        Build frequencies of all prefix balances.
        -------------------------------------------------------------*/
        for (char ch : s) {
            if (ch == '1')
                currentBalance++;
            else
                currentBalance--;

            if (currentBalance <= balanceShift)
                invalidPrefixes++;

            balanceFrequency[currentBalance]++;
        }

        // Reset to the initial prefix balance (0).
        currentBalance = balanceShift;

        /*------------------------------------------------------------
        Process every starting index.
        -------------------------------------------------------------*/
        for (int start = 0; start < n; start++) {

            // Number of possible ending positions.
            int totalFuturePrefixes = n - start;

            // Valid endings = total endings - invalid endings.
            answer += totalFuturePrefixes - invalidPrefixes;

            // Remove the prefix ending at 'start'
            // because it won't be available for future iterations.
            if (s[start] == '1')
                currentBalance++;
            else
                currentBalance--;

            balanceFrequency[currentBalance]--;

            /*
            Update invalidPrefixes.

            Invariant:
            invalidPrefixes =
            number of remaining prefix balances <= currentBalance.
            */

            if (s[start] == '1') {
                // Threshold increased by one.
                // Prefixes exactly at the new balance
                // become newly invalid.
                invalidPrefixes += balanceFrequency[currentBalance];
            }
            else {
                // Threshold decreased by one.

                // Removed prefix was previously counted.
                invalidPrefixes--;

                // Prefixes at (currentBalance + 1)
                // are no longer invalid.
                invalidPrefixes -= balanceFrequency[currentBalance + 1];
            }
        }

        return answer;
    }
};
