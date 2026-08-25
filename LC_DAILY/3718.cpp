#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int missingMultiple(vector<int>& nums, int k) {
//         unordered_set<int> st(nums.begin(), nums.end());

//         int i=1;
//         while(true){
//             int temp=k*i;
//             if(!st.count(temp)) return temp;
//             i++;
//         }

//         return -1;
//     }
// };

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int current = k;

        for (int num : nums) {
            if (num > current) {
                return current;
            }

            if (num == current) {
                current += k;
            }
        }

        return current;
    }
};