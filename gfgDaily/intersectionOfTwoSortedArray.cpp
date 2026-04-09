#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        // code here
        int idx1 = 0, idx2 = 0;
        vector<int> ans;

        while (idx1 < a.size() && idx2 < b.size()) {
            int ele1 = a[idx1];
            int ele2 = b[idx2];

            if (ele1 == ele2) {
                if (ans.empty() || ans.back() != ele1) {
                    ans.push_back(ele1);
                }
                idx1++;
                idx2++;
            }
            else if (ele1 > ele2) {
                idx2++;
            }

            else {
                idx1++;
            }
        }

        return ans;
    }

};