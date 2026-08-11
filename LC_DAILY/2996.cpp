#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int seq_pref_sum = nums[0];

        unordered_set<int> st(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1] + 1) break;
            seq_pref_sum += nums[i];
        }

        while (true) {
            if (st.find(seq_pref_sum) == st.end()) break;
            seq_pref_sum++;
        }

        return seq_pref_sum;
    }
};