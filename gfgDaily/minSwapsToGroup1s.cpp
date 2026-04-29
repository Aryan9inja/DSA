#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        int totalOnes = 0;

        for (int x : arr) {
            if (x == 1) totalOnes++;
        }

        if (totalOnes == 0) return -1;

        int currentOnes = 0;
        for (int i = 0; i < totalOnes; i++) {
            if (arr[i] == 1) currentOnes++;
        }

        int minSwaps = totalOnes - currentOnes;

        for (int i = totalOnes; i < n; i++) {
            if (arr[i - totalOnes] == 1) currentOnes--;
            if (arr[i] == 1) currentOnes++;

            minSwaps = min(minSwaps, totalOnes - currentOnes);
        }

        return minSwaps;
    }
};