#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    static bool cmp(vector<int> a, vector<int> b){
        return a[1] < b[1];
    }   
  
    vector<int> maxMeetings(int n, vector<int> &start, vector<int> &end) {
        vector<vector<int>> timePair(n);
        
        for(int i=0; i<n; i++){
            timePair[i]={start[i], end[i], i};
        }
        
        sort(timePair.begin(), timePair.end(), cmp);
        
        vector<int> ans;
        ans.push_back(timePair[0][2]+1);
        int ansEnd = timePair[0][1];
        
        for(int i=1; i<n; i++){
            if(timePair[i][0] > ansEnd){
                ans.push_back(timePair[i][2]+1);
                ansEnd = timePair[i][1];
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};