#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int minIdx = -1;
        int maxIdx = -1;

        bool isAscending = true;
        bool isDescending = true;

        for (int i = 0; i < n; i++) {
            if (minIdx == -1 || nums[i] < nums[minIdx]) {
                minIdx = i;
            }
            if (maxIdx == -1 || nums[i] > nums[maxIdx]) {
                maxIdx = i;
            }
        }

        int i = minIdx;
        do {
            int nextIdx = (i + 1) % n;
            if (nextIdx != minIdx && nums[nextIdx] != nums[i] + 1) {
                isAscending = false;
                break;
            }
            i = nextIdx;
        } while (i != minIdx);

        i = maxIdx;
        do {
            int nextIdx = (i + 1) % n;
            if (nextIdx != maxIdx && nums[nextIdx] != nums[i] - 1) {
                isDescending = false;
                break;
            }
            i = nextIdx;
        } while (i != maxIdx);

        if (!isAscending && !isDescending)
            return -1;

        int ans = INT_MAX;

        if (isAscending) {
            int leftRotations = minIdx;
            ans = min(ans, leftRotations);

            if (minIdx > 0) {
                // reverse -> left -> reverse
                int rightRotations = n - minIdx;
                ans = min(ans, 2 + rightRotations);
            }
        }

        if (isDescending) {
            int newMinIdx = (n - maxIdx) % n;
            ans = min(ans, 1 + newMinIdx);

            int leftRotationsBeforeReverse = maxIdx;
            ans = min(ans, leftRotationsBeforeReverse + 1);
        }

        return ans;
    }
};