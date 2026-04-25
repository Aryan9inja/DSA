#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> reducePairs(vector<int>& arr) {
        vector<int> ans;

        for (int ele : arr) {
            // stack not empty and diffrent signs
            while (!ans.empty() && ans.back() * ele < 0) {
                int top = ans.back();

                if (abs(top) > abs(ele)) {
                    ele = top;
                    ans.pop_back();
                }
                else if (abs(top) < abs(ele)) {
                    ans.pop_back();
                }
                else {
                    ans.pop_back();
                    ele = 0;
                    break;
                }
            }

            if (ele != 0) {
                ans.push_back(ele);
            }
        }

        return ans;
    }
};