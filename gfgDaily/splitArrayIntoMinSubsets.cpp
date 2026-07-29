#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubsets(vector<int>& arr) {
        unordered_set<int> s(arr.begin(), arr.end());

        int count = 0;
        for (int x : arr) {
            if (s.find(x - 1) == s.end()) {
                count++;
            }
        }
        return count;
    }
};
