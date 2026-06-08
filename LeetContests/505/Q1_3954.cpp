#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(string& curr, vector<string>& res, int n, int k, int idx, int currCost, bool prevOne) {
        if (idx == n) {
            res.push_back(curr);
            return;
        }

        curr.push_back('0');
        solve(curr, res, n, k, idx + 1, currCost, false);
        curr.pop_back();

        if (!prevOne && (currCost + idx) <= k) {
            curr.push_back('1');
            solve(curr, res, n, k, idx + 1, currCost, true);
            curr.pop_back();
        }
    }

    vector<string> generateValidStrings(int n, int k) {
        vector<string> res;
        string
    }
};