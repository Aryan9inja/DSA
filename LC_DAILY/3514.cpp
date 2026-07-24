#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> pairXorSet;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                pairXorSet.insert(nums[i] ^ nums[j]);
            }
        }

        unordered_set<int> tripletXorSet(nums.begin(), nums.end());

        for (int k = 0; k < n; ++k) {
            for (int val : pairXorSet) {
                tripletXorSet.insert(val ^ nums[k]);
            }
        }

        return tripletXorSet.size();
    }
};