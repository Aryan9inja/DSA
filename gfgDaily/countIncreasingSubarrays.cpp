#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        int count = 0;
        int len = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i - 1] < arr[i]) {
                count += len;
                len++;
            } else {
                len = 1;
            }
        }
        return count;
    }
};
