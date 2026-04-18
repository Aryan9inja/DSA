#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOnes(vector<int>& arr) {
        int totalOnes = 0;
        
        // Step 1: Count total 1s
        for (int x : arr) {
            if (x == 1) totalOnes++;
        }

        // Step 2: Apply Kadane on transformed values
        // +1 for 0
        // -1 for 1
        // Then kadane algo to find max sum subarray
        int currGain = 0, maxGain = 0;

        for (int x : arr) {
            int val = (x == 0) ? 1 : -1;

            currGain = max(val, currGain + val);
            maxGain = max(maxGain, currGain);
        }

        // Step 3: Add gain to total ones
        return totalOnes + maxGain;
    }
};