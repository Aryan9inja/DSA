#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(string moves) {
        int up = 0, down = 0, left = 0, right = 0, underscore = 0;

        for (char move : moves) {
            if (move == 'U') up++;
            else if (move == 'D') down++;
            else if (move == 'L') left++;
            else if (move == 'R') right++;
            else underscore++;
        }

        int dis = abs(up - down) + abs(left - right);
        return dis + underscore;
    }
};