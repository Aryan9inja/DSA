#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for (const string& pattern : patterns) {
            size_t pos = word.find(pattern);
            if (pos != string::npos)
                cnt++;
        }
        return cnt;
    }
};