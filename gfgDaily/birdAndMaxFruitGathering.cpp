#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFruits(vector<int>& arr, int m) {
        int n = arr.size();

        int win = 0;
        for (int i = 0; i < m; i++) {
            win += arr[i];
        }
        int maxi = win;

        int i = 0;
        int j = m;
        do {
            win += arr[j % n];
            win -= arr[i % n];
            maxi = max(maxi, win);
            i++;
            j++;
        } while ((i % n) != 0);

        return maxi;
    }
};