#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canAliceWin(int n) {
        int take = 10, k = 0;
        while (n >= take) {
            n -= take;
            take--;
            k++;
        }
        return k % 2 == 1;
    }
};