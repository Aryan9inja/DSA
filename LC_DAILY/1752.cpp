#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int miniIndex = 0;
        for (int i = 1;i < nums.size();i++) {
            if (nums[i] < nums[i - 1]) {
                miniIndex = i;
            }
        }

        int start = miniIndex;
        int next;
        do {
            if (start == nums.size() - 1) {
                next = 0;
            }
            else {
                next = start + 1;
            }

            if (next == miniIndex) continue;

            if (nums[next] >= nums[start]) {
                start = next;
                continue;
            }
            else {
                return false;
            }
        } while (next != miniIndex);

        return true;
    }
};