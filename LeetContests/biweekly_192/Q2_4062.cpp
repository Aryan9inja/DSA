#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        if (source.size() == 1) {
            return source[0] == target[0];
        }

        long long sourceSum = 0;
        long long targetSum = 0;

        for (int& x : source) sourceSum += x;
        for (int& x : target) targetSum += x;

        return sourceSum == targetSum;
    }
};