#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    static bool comparator(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]){
            return b[1]<a[1];
        }

        return a[0]<b[0];
    }

public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comparator);

        int n = envelopes.size();
        vector<int> ans;
        ans.push_back(envelopes[0][1]);

        for(int i=1; i<n; i++){
            if(envelopes[i][1] > ans.back()){
                ans.push_back(envelopes[i][1]);
            }
            else{
                int index = lower_bound(ans.begin(), ans.end(), envelopes[i][1]) - ans.begin();
                ans[index]= envelopes[i][1];
            }
        }
        return ans.size();
    }
};