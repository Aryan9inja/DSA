#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n+1, 0);
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            prefix[i+1] = sum; 
        }

        vector<int> ans;
        ans.reserve(n);

        for(int i = 0; i < n; i++){
            int leftContri = i*nums[i] - prefix[i];
            int rightContri = (sum - prefix[i+1]) - (n-i-1)*nums[i];

            ans.push_back(leftContri + rightContri);
        }
        return ans;
    }
};