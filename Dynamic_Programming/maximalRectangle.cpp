#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> nextSmaller(vector<int> heights, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            int curr = heights[i];
            while (s.top() != -1 && heights[s.top()] >= curr) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmaller(vector<int> heights, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int curr = heights[i];
            while (s.top() != -1 && heights[s.top()] >= curr) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    // Logic from largest rectangle in histogram
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> next(n);
        next = nextSmaller(heights, n);

        vector<int> prev(n);
        prev = prevSmaller(heights, n);

        int area = 0;
        for (int i = 0; i < n; i++) {
            int h = heights[i];
            if (next[i] == -1) {
                next[i] = n;
            }
            int w = next[i] - prev[i] - 1;

            area = max(h * w, area);
        }

        return area;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxi = INT_MIN;

        vector<int> histogram(matrix[0].size(), 0);
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<histogram.size(); j++){
                if(matrix[i][j]=='1'){
                    histogram[j]++;
                }
                else{
                    histogram[j] = 0;
                }
            }
            maxi = max(maxi, largestRectangleArea(histogram));
        }

        return maxi;
    }
};