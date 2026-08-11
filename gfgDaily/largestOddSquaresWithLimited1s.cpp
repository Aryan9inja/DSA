#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestSquare(vector<vector<int>>& mat, vector<vector<int>>& queries, int k) {
        int n = mat.size(), m = mat[0].size();

        // Build a 2D prefix sum array for fast submatrix sum queries.
        vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefix[i + 1][j + 1] = prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j] + mat[i][j];
            }
        }

        vector<int> res;

        // Process each query independently.
        for (auto& q : queries) {
            int i = q[0], j = q[1];

            // Find the maximum possible radius within matrix boundaries.
            int minDist = min({ i, j, n - i - 1, m - j - 1 });

            // If the center cell itself exceeds k, no valid square exists.
            if (mat[i][j] > k) {
                res.push_back(-1);
                continue;
            }

            // Binary search for the largest valid square radius.
            int lo = 0, hi = minDist, best = 0;

            while (lo <= hi) {
                int mid = (lo + hi) / 2;

                // Calculate the boundaries of the current square.
                int r1 = i - mid;
                int c1 = j - mid;
                int r2 = i + mid;
                int c2 = j + mid;

                // Find the square sum using the prefix sum array.
                int sum = prefix[r2 + 1][c2 + 1] - prefix[r1][c2 + 1] - prefix[r2 + 1][c1] + prefix[r1][c1];

                // If the sum is within k, try a larger square.
                if (sum <= k) {
                    best = mid;
                    lo = mid + 1;
                }
                else {
                    // Otherwise, try a smaller square.
                    hi = mid - 1;
                }
            }

            // Radius r gives a square of side 2*r + 1.
            res.push_back(2 * best + 1);
        }

        return res;
    }

};
