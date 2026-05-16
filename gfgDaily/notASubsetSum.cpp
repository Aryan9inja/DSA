#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSmallest(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int res = 1;

        for (int i = 0; i < arr.size() && res >= arr[i]; i++) {
            res += arr[i];
        }

        return res;
    }
};
