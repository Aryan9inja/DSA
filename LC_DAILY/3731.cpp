#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        // sort(nums.begin(), nums.end());

        // vector<int> ans;
        // for(int i = 0; i<nums.size()-1; i++){
        //     int curr = nums[i];
        //     int find = curr + 1;

        //     while(nums[i+1] != find){
        //         ans.push_back(find);
        //         find++;
        //     }
        // }

        // return ans;

        vector<int> lookup(101, 0);
        int maxi = 0;
        int mini = 101;

        for (int& n : nums) {
            lookup[n] = 1;
            maxi = max(maxi, n);
            mini = min(mini, n);
        }

        vector<int> ans;
        for (int i = mini; i <= maxi; i++) {
            if (!lookup[i]) ans.push_back(i);
        }

        return ans;
    }
};