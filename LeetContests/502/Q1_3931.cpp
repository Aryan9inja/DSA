#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int n = s.length();
        for(int i=0; i<n-1; i++){
            int diff = abs(s[i]-s[i+1]);

            if(diff > 2) return false;
        }
        return true;
    }
};