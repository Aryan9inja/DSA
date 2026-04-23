#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        int sum = 0;
        for(int& a : arr){
            sum += a;
        }
        
        int curr = 0;
        for(int& a : arr){
            curr += a;
            if (sum - curr == curr){
                return true;
            }
        }
        
        return false;
    }
};
