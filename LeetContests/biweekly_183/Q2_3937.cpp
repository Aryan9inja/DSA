#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> c_even(k, 0);
        vector<int> c_odd(k, 0);

        for(int i=0; i<n; i++){
            int rem = nums[i]%k;

            for(int target = 0; target<k; target++){
                int dist = abs(rem - target);
                dist = min(dist, k-dist);

                if(i&1){
                    c_odd[target]+=dist;
                }else{
                    c_even[target]+=dist;
                }
            }
        }

        int minOps = -1;

        for(int x=0; x<k; x++){
            for(int y=0; y<k; y++){
                if(x==y) continue;

                int currOps = c_even[x] + c_odd[y];

                if(minOps == -1 || currOps < minOps){
                    minOps = currOps;
                }
            }
        }
        return minOps;
    }
};