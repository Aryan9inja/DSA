#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    static bool cmp(pair<double, pair<int, int>> a, pair<double, pair<int, int>> b){
        return a.first > b.first;
    }
  
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<pair<double, pair<int, int>>> items;
        
        for(int i=0; i<n; i++){
            // rounded to 6 decimal places
            double perUnitValue = (1.0 * val[i])/wt[i];
            pair<int, int> stats = make_pair(wt[i], val[i]);
            pair<double, pair<int, int>> item = make_pair(perUnitValue, stats);
            items.push_back(item);
        }
        
        sort(items.begin(), items.end(), cmp);
        
        double totalVal = 0;
        for(auto item : items){
            if(item.second.first > capacity){
                totalVal += capacity * item.first;
                capacity = 0;
                return totalVal;
            }
            else{
                totalVal += item.second.second;
                capacity -= item.second.first;
            }
        }
        
        return totalVal;
    }
};
