#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1,
                                            vector<vector<int>>& series2) {
        int n = series1.size();
        int m = series2.size();

        int p1 = 0;
        int p2 = 0;

        vector<vector<int>> res;

        while (p1 < n && p2 < m) {
            if (series1[p1][0] == series2[p2][0]) {
                res.push_back(
                    {series1[p1][0], series1[p1][1] + series2[p2][1]});
                p1++;
                p2++;
            }
            else if(series1[p1][0] < series2[p2][0]){
                res.push_back(
                    {series1[p1][0], series1[p1][1] + series2[p2][1]});
                p1++;
            }
            else if(series1[p1][0] > series2[p2][0]){
                res.push_back(
                    {series2[p2][0], series1[p1][1] + series2[p2][1]});
                p2++;
            }
        }

        while(p1<n){
            res.push_back({series1[p1][0], series1[p1][1]});
            p1++;
        }

        while(p2<m){
            res.push_back({series2[p2][0], series2[p2][1]});
            p2++;
        }

        return res;
    }
};