#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freq;

        int maxLen = 0;

        int j = 0;
        for(int i=0; i<n; i++){
            int curr = nums[i];
            freq[curr]++;

            while(freq[curr] > k){
                freq[nums[j]]--;
                j++;
            }

            maxLen = max(maxLen, i-j+1);
        }

        return maxLen;
    }
};