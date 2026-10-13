#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> update(int n, vector<int>& updates) {
        vector<int> arr(n, 0);

        for (int j : updates)
            ++arr[j - 1];

        int count = 0;

        for (int i = 0; i < n; ++i) {
            count += arr[i];
            arr[i] = count;
        }

        return arr;
    }
};
