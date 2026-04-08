#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        sort(prices.begin(), prices.end());
        
        int mini = 0;
        int buy = 0;
        int freeC = prices.size()-1;
        
        while(buy<=freeC){
            mini = mini + prices[buy++];
            freeC = freeC - k;
        }
        
        int maxi = 0;
        buy = prices.size()-1;
        freeC = 0;
        
        while(freeC<=buy){
            maxi = maxi + prices[buy--];
            freeC = freeC + k;
        }
        
        return {mini, maxi};
    }
};