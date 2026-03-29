#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        /*
        // My solution
        if(s1==s2) return true;

        // After swap1
        swap(s1[0], s1[2]);
        if(s1 == s2) return true;

        // Restructure s1 and do swap2
        swap(s1[0], s1[2]);
        swap(s1[1], s1[3]);
        if(s1 == s2) return true;

        // Do swap1 along with already done swap2
        swap(s1[0], s1[2]);
        if(s1 == s2) return true;

        return false;
        */

        // Solution without swap
        return ((s1[0] == s2[0] && s1[2] == s2[2]) ||
        (s1[0] == s2[2] && s1[2] == s2[0])) &&
        ((s1[1] == s2[1] && s1[3] == s2[3]) ||
        (s1[1] == s2[3] && s1[3] == s2[1]));
    }
};