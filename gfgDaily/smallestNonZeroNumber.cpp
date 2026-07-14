#include<bits/stdc++.h>
using namespace std;

class Solution {
    // My solution - Binary search
    // O(n*log(maxElement))
    /*
    bool canSolve(vector<int>& arr, int x, int maxi) {
        long long current_x = x;

        for (int y : arr) {
            current_x = 2 * current_x - y;

            if (current_x < 0) {
                return false;
            }

            if (current_x >= maxi) {
                return true;
            }
        }

        return true;
    }

    public:
    int find(vector<int>& arr) {
        int maxi = 0;
        for (int x : arr) {
            maxi = max(maxi, x);
        }

        int s = 0;
        int e = maxi + 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            if (canSolve(arr, mid, maxi))
                e = mid;
            else
                s = mid + 1;
        }

        return s;
    }
    */

    // Optimal Reverse greedy + maths
    // O(n)
public:
    int find(vector<int>& arr) {

        int need = 0;

        // Process the array from right to left
        for (int i = arr.size() - 1; i >= 0; i--) {

            // Minimum value required before processing arr[i]
            need = (need + arr[i] + 1) / 2;
        }

        return need;
    }
};
