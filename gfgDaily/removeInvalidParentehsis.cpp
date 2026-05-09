#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int count = 0;

        for (char c : s) {
            // Increment for opening bracket
            if (c == '(')
                count++;

            // Decrement for closing bracket
            else if (c == ')') {
                count--;

                // If at any point count becomes negative,
                // more ')' than '(' means invalid string
                if (count < 0)
                    return false;
            }
        }

        // Valid only if all '(' are matched
        return count == 0;
    }

    // Function to generate all valid strings by removing minimum parentheses
    vector<string> validParenthesis(string s) {

        unordered_set<string> visited;
        queue<string> q;
        vector<string> result;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {

            string curr = q.front();
            q.pop();

            // Check if current string is valid
            if (isValid(curr)) {
                result.push_back(curr);
                found = true;
            }

            // If valid string found at this level,
            // do not generate next level this ensures minimum removals
            if (found)
                continue;

            // Generate all possible strings by removing one parenthesis
            for (int i = 0; i < curr.length(); i++) {

                // Skip non-parenthesis characters
                if (curr[i] != '(' && curr[i] != ')')
                    continue;

                // Remove character at index i
                string next = curr.substr(0, i) + curr.substr(i + 1);

                // Add new string if not already visited
                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }

        return result;
    }
};
