#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkElements(int start, int end, vector<int>& arr) {
        int n = arr.size();

        if (n < end - start + 1)
            return false;

        int range = end - start;

        // We can use conversion to negative values
        // and checking abs each iteration
        for (int i = 0; i < n; i++) {
            int val = abs(arr[i]);

            if (val >= start && val <= end) {
                int idx = val - start;
                if (i < n && arr[idx]>0) {
                    arr[idx] = -arr[idx];
                }
            }
        }

        for (int i = 0; i <= range; i++) {
            if (arr[i] > 0)
                return false;
        }
        return true;
    }
};
