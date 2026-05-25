#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> st;
        int points = 0;
        for (const char& ch : password) {
            if (st.count(ch)) {
                continue;
            }

            st.insert(ch);

            if (ch >= 'a' && ch <= 'z') points += 1;
            else if (ch >= 'A' && ch <= 'Z') points += 2;
            else if (ch >= '0' && ch <= '9') points += 3;
            else points += 5;
        }

        return points;
    }
};