#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        vector<bool> vis(n, false);

        queue<int> q;

        q.push(start);
        vis[start] = true;

        while(!q.empty()){
            int i = q.front();
            q.pop();

            if(arr[i]==0) return true;

            int ahead = i + arr[i];
            int behind = i - arr[i];

            if(ahead < n && !vis[ahead]){
                q.push(ahead);
                vis[ahead]=true;
            }

            if(behind >=0 && !vis[behind]){
                q.push(behind);
                vis[behind]=true;
            }
        }
        return false;
    }
};