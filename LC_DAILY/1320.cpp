#include<bits/stdc++.h>
using namespace std;

class Solution {
    // memo[f1][f2][index]
    // 27 is used because 0-25 are letters A-Z, and 26 represents a finger not yet placed.
    int memo[27][27][300];

    // Helper to calculate distance based on the 1D character positions
    int getDistance(int from, int to) {
        if (from == 26) return 0; // Cost is 0 if the finger hasn't been placed yet
        
        int fromX = from / 6;
        int fromY = from % 6;
        int toX = to / 6;
        int toY = to % 6;
        
        return abs(fromX - toX) + abs(fromY - toY);
    }

    int solve(string& word, int f1, int f2, int index) {
        // Base case: typed the whole word
        if (index == word.length()) return 0;

        // Return memoized result if already calculated
        if (memo[f1][f2][index] != -1) return memo[f1][f2][index];

        // The target character we need to type next
        int target = word[index] - 'A';

        // Option 1: Move finger 1 to the target
        int moveF1 = getDistance(f1, target) + solve(word, target, f2, index + 1);

        // Option 2: Move finger 2 to the target
        int moveF2 = getDistance(f2, target) + solve(word, f1, target, index + 1);

        // Save to memo table and return the minimum
        return memo[f1][f2][index] = min(moveF1, moveF2);
    }

public:
    int minimumDistance(string word) {
        // Initialize memoization table with -1
        memset(memo, -1, sizeof(memo));
        
        // Start with both fingers in the "unplaced" state (26)
        return solve(word, 26, 26, 0);
    }
};