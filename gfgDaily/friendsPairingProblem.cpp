#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countFriendsPairings(int n) {
        int a = 1, b = 2, c = 0;

        // handling base cases
        if (n <= 2) {
            return n;
        }

        // iterating from 3 to n
        for (int i = 3; i <= n; i++) {
            // applying recurrence relation:
            // f(i) = f(i-1) + (i-1) * f(i-2)
            c = b + (i - 1) * a;

            // updating previous two values
            a = b;
            b = c;
        }
        return c;
    }
};
