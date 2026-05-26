// LC 815 - Bus Routes
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
        if (source == target)
            return 0;

        int n = routes.size();

        unordered_map<int, vector<int>> stopToBus;
        for (int bus = 0; bus < n; bus++) {
            for (int stop : routes[bus]) {
                stopToBus[stop].push_back(bus);
            }
        }

        queue<int> q;
        unordered_set<int> visStops;
        vector<bool> visBuses(n, false);

        q.push(source);
        visStops.insert(source);

        int busCnt = 0;
        while(!q.empty()){
            int sz = q.size();
            busCnt++;

            while(sz--){
                int currStop = q.front();
                q.pop();

                for(int bus : stopToBus[currStop]){
                    if(visBuses[bus]) continue;

                    visBuses[bus] = true;

                    for(int nextStop : routes[bus]){
                        if(nextStop == target) return busCnt;

                        if(!visStops.count(nextStop)){
                            visStops.insert(nextStop);
                            q.push(nextStop);
                        }
                    }
                }
            }
        }
        return -1;
    }
};