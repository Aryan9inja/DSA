#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coin(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = n - 1;
        while (j - i + 1 > 1) {
            if (arr[i] < arr[j]) {
                j--;
            }
            else {
                i++;
            }
        }
        return arr[i];
    }
};