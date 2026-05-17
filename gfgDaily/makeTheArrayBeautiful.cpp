#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
	vector<int> makeBeautiful(vector<int>& arr) {
		vector<int> st;
		
		for (int i = 0; i < arr.size(); i++) {
			if (st.empty()) {
				st.push_back(arr[i]);
			} else {
				bool top_is_positive = st.back() >= 0;
				bool curr_is_positive = arr[i] >= 0;
				
				if (top_is_positive != curr_is_positive) {
					st.pop_back();
				} else {
					st.push_back(arr[i]);
				}
			}
		}
		
		return st;
	}
};
