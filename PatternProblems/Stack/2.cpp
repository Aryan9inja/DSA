// LC 50 - Next Greater Element II
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(nums.size(), -1);

        for (int i = 0; i < 2 * n; i++) {
            int num = nums[i % n];

            while (!st.empty() && nums[st.top()] < num) {
                ans[st.top()] = num;
                st.pop();
            }

            if (i < n) {
                st.push(i);
            }
        }

        return ans;
    }
};