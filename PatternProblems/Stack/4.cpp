// LC 84 - Largest Rectangle in Histogram
#include<bits/stdc++.h>
using namespace std;

// MINE
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> nextSmaller(n);
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(st.empty()) nextSmaller[i] = n;
            else nextSmaller[i] = st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        vector<int> prevSmaller(n);
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(st.empty()) prevSmaller[i] = -1;
            else prevSmaller[i] = st.top();

            st.push(i);
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            int width = nextSmaller[i] - prevSmaller[i] - 1;
            ans = max(ans, width*heights[i]);
        }

        return ans;
    }
};

// Optimal
class SolutionX {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxArea = 0;

        for(int i = 0; i <= n; i++) {
            int h = (i == n ? 0 : heights[i]);

            while(!st.empty() && heights[st.top()] > h) {
                int height = heights[st.top()];
                st.pop();

                int right = i;
                int left = st.empty() ? -1 : st.top();

                int width = right - left - 1;
                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};