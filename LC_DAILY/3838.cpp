#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for (auto& word : words) {
            int w = 0;
            for (char c : word) {
                w += weights[c - 'a'];
            }
            w %= 26;
            char temp = (26 - w - 1) + 'a';
            ans += temp;
        }

        return ans;
    }
};