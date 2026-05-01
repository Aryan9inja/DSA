#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        int n = arr.size();

        priority_queue<int, vector<int>, greater<int>> minHeap;

        vector<int> ans(n);

        for (int i = 0; i < arr.size(); i++) {
            minHeap.push(arr[i]);

            if (minHeap.size() > k) minHeap.pop();

            ans[i] = minHeap.size() < k ? -1 : minHeap.top();
        }
        return ans;
    }
};