/*
sort all dimensions for every cuboid
the max dimension for each cuboid should be considered height
Now, the question has converted like Russian doll
Solve like russian doll
Sort all cuboids based on width (first column)
Now problem is longest increasing subsequence. LOL
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool check(vector<int> base, vector<int> newBox) {
        if (newBox[0] <= base[0] && newBox[1] <= base[1] &&
            newBox[2] <= base[2]) {
            return true;
        }
        return false;
    }

    int solve(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--) {
            for (int prev = curr - 1; prev >= -1; prev--) {
                int include = 0;
                if (prev == -1 || check(arr[curr], arr[prev])) {
                    include = arr[curr][2] + nextRow[curr + 1];
                }

                int exclude = 0 + nextRow[prev + 1];

                // to mitigate invalid index
                currRow[prev + 1] = max(include, exclude);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }

public:
    int maxHeight(vector<vector<int>>& cuboids) {
        // sort all dimensions
        for (auto& a : cuboids) {
            sort(a.begin(), a.end());
        }

        // sort based on width
        sort(cuboids.begin(), cuboids.end());

        return solve(cuboids);
    }
};