#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for (int& num : nums) {
            string n = to_string(num);
            for (const char& c : n) {
                ans.push_back(c - '0');
            }
        }

        return ans;
    }
};