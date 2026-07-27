#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi1 = 0;
        int maxi2 = 0;

        for (int& n : nums) {
            if (n > maxi1) {
                maxi2 = maxi1;
                maxi1 = n;
            }
            else if (n > maxi2) {
                maxi2 = n;
            }
        }

        return (maxi1 - 1) * (maxi2 - 1);
    }
};