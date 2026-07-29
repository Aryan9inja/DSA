#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper to clamp values at 'k'. Since we only care if permutations >= k,
    // capping prevents long long arithmetic overflow without losing useful information.
    long long safeCap(long long val, int k) {
        return min(val, (long long)k);
    }

    // Computes nCr (n choose r) with an early cap at 'k'
    long long nCr(int n, int r, int k) {
        if (r < 0 || r > n) return 0;

        // Property: nCr == nC(n-r). Using the smaller 'r' minimizes iteration steps.
        r = min(r, n - r);

        long long res = 1;
        for (int i = 1; i <= r; i++) {
            // IMPORTANT: (n - r + i) must be multiplied before dividing by 'i'
            // to prevent integer truncation errors (e.g. 5/2 = 2 in C++ integer division).
            res = res * (n - r + i) / i;

            // Cap early to prevent potential overflow in subsequent loop steps
            if (res >= k) return k;
        }
        return res;
    }

    string smallestPalindrome(string s, int k) {
        int n = s.length();

        // 1. Handle odd length palindromes: isolate the middle character
        char mid = ' ';
        if (n & 1) {
            mid = s[n / 2];
        }

        // 2. Count character frequencies for the half-string.
        // Since a palindrome is symmetric, we only need to construct the left half.
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Halve the counts because left Half receives exactly half of each character pair
        for (int& f : freq) {
            f /= 2;
        }

        string leftHalf = "";
        int leftLen = n / 2;

        // 3. Digit-by-digit (Lexicographical) Construction of Left Half
        for (int i = 0; i < leftLen; i++) {
            bool placedChar = false;

            // Try characters from 'a' to 'z' in alphabetical order to guarantee
            // the smallest possible lexicographical result.
            for (int j = 0; j < 26; j++) {
                if (freq[j] <= 0) continue;

                // Temporarily place character 'j + a' at index 'i'
                freq[j]--;

                // --- Calculate distinct permutations of remaining characters ---
                // Formula for multiset permutations: Total! / (c1! * c2! * ... * c26!)
                // Evaluated sequentially as: (Total c1) * (Remaining c2) * ...
                long long ways = 1;
                int letters = 0;
                for (int c = 0; c < 26; c++) {
                    letters += freq[c];
                }

                for (int c = 0; c < 26; c++) {
                    if (freq[c] <= 0) continue;

                    long long combinations = nCr(letters, freq[c], k);

                    // Overflow Guard: Safe check for (ways * combinations > k)
                    // Equivalent to: combinations > k / ways
                    if (ways > 0 && combinations > (k + ways - 1) / ways) {
                        ways = k;
                    }
                    else {
                        ways *= combinations;
                    }

                    ways = min(ways, (long long)k); // Ensure 'ways' never exceeds 'k'
                    letters -= freq[c];
                }

                // Decision branch:
                if (ways >= k) {
                    // The k-th permutation lies inside the set of strings starting with this char.
                    // Commit to character 'j' and move to the next index (i + 1).
                    leftHalf.push_back(j + 'a');
                    placedChar = true;
                    break;
                }

                // The k-th permutation lies beyond this character choice.
                // Skip all 'ways' permutations starting with 'j', adjust k, and backtrack.
                k -= ways;
                freq[j]++; // Backtrack character count
            }

            // If no character could be placed, k exceeds total possible permutations
            if (!placedChar) {
                return "";
            }
        }

        // 4. Mirror the left half to form the final palindrome
        string rev = leftHalf;
        reverse(rev.begin(), rev.end());

        if (mid != ' ') {
            leftHalf.push_back(mid);
        }

        return leftHalf + rev;
    }
};