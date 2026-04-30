#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool recursive(vector<int>& arr, int i, int n) {
        // leaf node
        if (i >= n / 2) return true;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // check left
        if (arr[i] < arr[left]) return false;

        // check right
        if (right < n && arr[i] < arr[right]) return false;

        return recursive(arr, left, n) &&
            (right >= n || recursive(arr, right, n));
    }

public:
    bool isMaxHeap(vector<int>& arr) {
        // return recursive(arr, 0, arr.size());

        int n = arr.size();

        // Traverse only internal nodes
        for (int i = 0; i <= (n - 2) / 2; i++) {
            // Check left child
            if (arr[2 * i + 1] > arr[i])
                return false;

            // Check right child (ensure index is valid)
            if (2 * i + 2 < n && arr[2 * i + 2] > arr[i])
                return false;
        }
        return true;
    }
};
