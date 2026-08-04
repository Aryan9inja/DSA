#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int res = 0;

        for (int i = 0; i < n; i++) {
            int val = arr[i] + k;

            int y = lower_bound(arr.begin(), arr.end(), val) - arr.begin();

            res += (y - i - 1);
        }
        return res;
    }
};
