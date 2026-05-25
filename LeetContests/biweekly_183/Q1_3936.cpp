#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int cntZeros = 0;
        for(const int &n : nums){
            if(n==0) cntZeros++;
        }

        if(!cntZeros) return 0;

        int swaps = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0 && i < nums.size()-cntZeros){
                swaps++;
            }
        }

        return swaps;
    }
};