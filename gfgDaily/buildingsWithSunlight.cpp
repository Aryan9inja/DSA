#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        int prevMax = 0;
        int cnt = 0;
        for(int height : arr){
            if(height >= prevMax) cnt++;
            
            prevMax = max(prevMax, height);
        }
        
        return cnt;
    }
};