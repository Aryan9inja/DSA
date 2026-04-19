#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> maxAtIdx(nums.size());
        int maxi = 0;
        for(int i=0; i<nums.size(); i++){
            maxAtIdx[i] = max(maxi, nums[i]);
            maxi = max(maxi, nums[i]);
        }

        vector<int> minAtIdx(nums.size());
        int mini = INT_MAX;
        for(int i=nums.size()-1; i>=0; i--){
            minAtIdx[i] = min(mini, nums[i]);
            mini = min(mini, nums[i]);
        }

        int minStability = INT_MAX;
        int minStabilityIdx = -1;
        for(int i=nums.size()-1; i>=0 ; i--){
            int score = maxAtIdx[i] - minAtIdx[i];
            if(score <= k){
                minStabilityIdx = i;
            }
        }
        return minStabilityIdx;
    }
};