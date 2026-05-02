#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPosition(int n) {
        bool set = 0;
        int ans = 0;
        int bitPos = 1;
        while (n != 0) {
            int bit = n & 1;
            n = n >> 1;

            if (bit == 1) {
                if (!set) {
                    ans = bitPos;
                    set = 1;
                }
                else return -1;
            }
            bitPos++;
        }
        return ans;
    }
};