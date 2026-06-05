// https://www.geeksforgeeks.org/problems/lexicographically-smallest-after-removing-k/1
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lexicographicallySmallest(string& s, int k) {
        string ans = "";
        int l = s.length();

        if (l & (l - 1))
            k += k;
        else
            k /= 2;

        if (k >= l)
            return "-1";

        stack<char> st;

        for (int i = 0; i < l; i++) {
            while (!st.empty() && k > 0 && st.top() > s[i]) {
                st.pop();
                k--;
            }
            st.push(s[i]);
        }

        if (k > 0)
            while (k--)
                st.pop();

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
