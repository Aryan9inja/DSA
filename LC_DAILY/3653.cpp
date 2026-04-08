#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto q : queries){
            int idx = q[0];
            int limit = q[1];
            int offset = q[2];
            int multiplier = q[3];

            while(idx<=limit){
                nums[idx] = (1LL * (nums[idx]%MOD) * (multiplier%MOD))% MOD;
                idx+=offset;
            }
        }
        int ans=0;
        for(int num : nums){
            ans = ans^num;
        }
        return ans;
    }
};