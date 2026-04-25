#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kthRemainingInteger(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int> prefix_evens(n+1, 0);
        for(int i =0 ; i<n; i++){
            prefix_evens[i+1] = prefix_evens[i] + (nums[i] & 1 ? 0 : 1);
        }
        
        vector<int> sol;
        for(auto query : queries){
            int l = query[0];
            int r = query[1];
            int k = query[2];

            auto mem = query;

            long long s = 1;
            long long e = 2e9;
            long long ans = -1;

            while(s <= e){
                long long mid = s + (e-s)/2;
                long long mid_val = 2 * mid;

                // if(l<0 || r>=nums.size() || l>r) continue;                
                auto it_s = nums.begin() + l;
                auto it_e = nums.begin() + r + 1;
                auto it_up = upper_bound(it_s, it_e, mid_val);

                int idx = distance(nums.begin(), it_up);

                long long removed_evens = prefix_evens[idx] - prefix_evens[l];
                long long remaining_evens = mid - removed_evens;

                if(remaining_evens >= k){
                    ans = mid_val;
                    e = mid - 1;
                }
                else{
                    s = mid + 1;
                }
            }
            sol.push_back((int)ans);
        }
        return sol;
    }
};