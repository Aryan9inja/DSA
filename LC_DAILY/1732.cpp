#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = 0;
        int curr = 0;
        for (const int& g : gain) {
            curr += g;
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};