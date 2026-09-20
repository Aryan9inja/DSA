#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            int c = 26 - (s[i] - 'a');
            ans += c * (i + 1);
        }
        return ans;
    }
};