#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Determinant using Gaussian elimination
    double determinant(vector<vector<double>> mat, int n) {
        double det = 1.0;

        for (int i = 0; i < n; i++) {
            // Find pivot
            int pivot = i;
            for (int j = i + 1; j < n; j++) {
                if (fabs(mat[j][i]) > fabs(mat[pivot][i]))
                    pivot = j;
            }

            // Swap rows
            if (i != pivot) {
                swap(mat[i], mat[pivot]);
                det *= -1;
            }

            // If pivot is zero → determinant = 0
            if (fabs(mat[pivot][i]) < 1e-9)
                return 0;

            det *= mat[i][i];

            // Eliminate below
            for (int j = i + 1; j < n; j++) {
                double factor = mat[j][i] / mat[i][i];
                for (int k = i; k < n; k++) {
                    mat[j][k] -= factor * mat[i][k];
                }
            }
        }

        return det;
    }

    int countSpanTree(int n, vector<vector<int>>& edges) {
        // Create an adjacency matrix
        vector<vector<int>> adj(n, vector<int>(n, 0));
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        // Creating laplacian matrix
        vector<vector<double>> laplacian(n, vector<double>(n, 0));

        for (int i = 0; i < n; i++) {
            int deg = 0;
            for (int j = 0; j < n; j++) {
                if (adj[i][j]) {
                    deg++;
                    if (i != j)
                        laplacian[i][j] = -1;
                }
            }
            laplacian[i][i] = deg;
        }

        // Creating minor laplacian matrix
        vector<vector<double>> laplacian_min(n - 1, vector<double>(n - 1));

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                laplacian_min[i][j] = laplacian[i][j];
            }
        }

        return (int)round(determinant(laplacian_min, n - 1));
    }
};
