#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int minDistance = INT_MAX;
        unordered_map<int, int> lastSeenIndex;

        for (int i = 0; i < nums.size(); ++i) {
            int originalValue = nums[i];

            // 1. Check if the current number is a mirror of something we've seen
            if (lastSeenIndex.count(originalValue)) {
                int distance = i - lastSeenIndex[originalValue];
                minDistance = min(minDistance, distance);
            }

            // 2. Calculate the mirror (reverse) of the current number
            int mirrorValue = reverseDigits(originalValue);

            // 3. Store the mirror's index so its "partner" can find it later
            lastSeenIndex[mirrorValue] = i;
        }

        return (minDistance == INT_MAX) ? -1 : minDistance;
    }

private:
    int reverseDigits(int n) {
        int reversed = 0;
        while (n > 0) {
            reversed = (reversed * 10) + (n % 10);
            n /= 10;
        }
        return reversed;
    }
};