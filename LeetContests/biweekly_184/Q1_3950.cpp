#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool consecutiveSetBits(int n) {
        int lastBit = 0;
        bool found = false;
        while(n>0){
            int currBit = n&1;
            n = n>>1;
            if(lastBit == 1 && currBit == 1){
                if(found) return false;
                found = true;
            }
            lastBit = currBit;
        }
        return found;
    }
};