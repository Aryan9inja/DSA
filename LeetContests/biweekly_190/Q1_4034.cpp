#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int sr = source[0], sc = source[1];
        int tr = target[0], tc = target[1];

        if (((sc + sr) % 2) != ((tc + tr) % 2)) {
            return -1;
        }

        if (sr == tr && sc == tc) {
            return 0;
        }

        if (abs(tr - sr) == abs(tc - sc)) {
            return 1;
        }

        return 2;
    }
};