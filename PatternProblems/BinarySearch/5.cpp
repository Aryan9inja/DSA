// LC 1011 - Capacity To Ship Packages Within D Days
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool canShip(vector<int>& weights, int capacity, int days) {
        int currSum = 0;
        int neededDays = 1;

        for(int w : weights) {
            if(currSum + w > capacity) {
                neededDays++;
                currSum = w;
            } else {
                currSum += w;
            }
        }

        return neededDays <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(), weights.end());
        int end = accumulate(weights.begin(), weights.end(), 0);

        while(start <= end) {
            int mid = start + (end - start) / 2;

            if(canShip(weights, mid, days)) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return start;
    }
};