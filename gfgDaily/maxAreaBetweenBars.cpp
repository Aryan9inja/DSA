#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int n = height.size();

        int i = 0, j = n - 1;

        while (i < j) {
            int width = j - i - 1;

            if (height[i] < height[j]) {
                res = max(res, width * height[i]);
                i++;
            }
            else if (height[j] < height[i]) {
                res = max(res, width * height[j]);
                j--;
            }
            else {
                res = max(res, width * height[i]);
                i++;
                j--;
            }
        }

        return res;
    }
};
