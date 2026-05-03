#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string g) {
        // if(s.length()!=g.length()) return false;

        // for(int i=0; i<s.length(); i++){
        //     for(int j=0; j<s.length(); j++){
        //         swap(g[0], g[s.length()-1-j]);
        //     }
        //     if(s==g) return true;
        // }
        // return false;

        if (s.length() != g.length()) return false;

        return (s + s).find(g) != string::npos;
    }
};