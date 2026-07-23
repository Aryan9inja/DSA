#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canRepresentBST(vector<int>& arr) {
        stack<int> s;

        int root = INT_MIN;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] < root)
                return false;

            while (!s.empty() && s.top() < arr[i]) {
                root = s.top();
                s.pop();
            }

            s.push(arr[i]);
        }
        return true;
    }
};
