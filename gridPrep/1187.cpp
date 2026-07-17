#include<bits/stdc++.h>
using namespace std;

// Custom hash function for pair<int, int>
struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<long long>()(((long long)p.first << 32) |
            (unsigned int)p.second);
    }
};

class Solution {
    int n;
    const int INF = 1e9 + 7;
    // Use the custom hash
    unordered_map<pair<int, int>, int, pair_hash> memo;
    set<int> st;

    int solve(vector<int>& arr1, int i, int prev) {
        if (i == n)
            return 0;

        // Check memo
        auto key = make_pair(i, prev);

        auto m_it = memo.find(key);
        if (m_it != memo.end())
            return m_it->second;

        int ans = INF;

        // Option 1: Keep arr1[i] if it's strictly greater than prev
        if (arr1[i] > prev) {
            ans = min(ans, solve(arr1, i + 1, arr1[i]));
        }

        // Option 2: Replace arr1[i] with the smallest value in arr2 greater
        // than prev
        auto it = st.upper_bound(prev);
        if (it != st.end()) {
            int val = *it;
            ans = min(ans, 1 + solve(arr1, i + 1, val));
        }

        return memo[key] = ans;
    }

public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        n = arr1.size();
        st.clear();
        memo.clear();

        for (int x : arr2)
            st.insert(x);

        // Start with prev = -1 (since constraints say values >= 0)
        int result = solve(arr1, 0, -1);

        return (result >= INF) ? -1 : result;
    }
};