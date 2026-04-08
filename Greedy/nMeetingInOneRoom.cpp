#include<bits/stdc++.h>
using namespace std;

// Activity Selection Problem
class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int,int> b){
        return a.second < b.second;
    }    
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<pair<int,int>> timePair(n);
        
        for(int i=0; i<n; i++){
            timePair[i]={start[i], end[i]};
        }
        
        sort(timePair.begin(), timePair.end(), cmp);
        
        int cnt = 1;
        int ansEnd = timePair[0].second;
        
        for(int i=1; i<n; i++){
            if(timePair[i].first > ansEnd){
                cnt++;
                ansEnd = timePair[i].second;
            }
        }
        
        return cnt;
    }
};