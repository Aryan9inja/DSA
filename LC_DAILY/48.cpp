#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();

        // Reverse array upside down
        int top=0;
        int bottom=n-1;
        while(top<bottom){
            for(int col=0;col<n;col++){
                swap(matrix[top][col],matrix[bottom][col]);
            }
            top++;
            bottom--;
        }

        // Get transpose of reversed array
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};