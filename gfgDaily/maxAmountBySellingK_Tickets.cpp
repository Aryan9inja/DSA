#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAmount(vector<int>& arr, int k) {
        int mod = 1000000007;
        int n = arr.size();
        priority_queue<int> q;

        // inserting values in priority queue.
        for (int i = 0; i < n; i++)
            q.push(arr[i]);

        int res = 0, x;

        // calculating answer modulo 1e9 + 7
        while (k && !q.empty()) {
            x = q.top();
            q.pop();
            res = (res + x) % mod;
            x--;
            k--;
            if (x)
                q.push(x);
        }
        return res;
    }
};
