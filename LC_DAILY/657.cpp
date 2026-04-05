#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int cntU=0, cntD=0, cntL=0, cntR=0;

        for(char move: moves){
            if(move=='U') cntU++;
            if(move=='D') cntD++;
            if(move=='L') cntL++;
            if(move=='R') cntR++;
        }

        if(cntU==cntD && cntL==cntR) return true;
        return false;
    }
};