#include<bits/stdc++.h>
using namespace std;

class SparseTable {
private:
    vector<vector<int>> mn;
    vector<vector<int>> mx;
    int n, K;

    int rangeMin(int l, int r) {
        int len = r - l + 1;

        int j = __lg(len);

        return min(mn[l][j], mn[r - (1 << j) + 1][j]);
    }

    int rangeMax(int l, int r) {
        int len = r - l + 1;

        int j = __lg(len);

        return max(mx[l][j], mx[r - (1 << j) + 1][j]);
    }

    void build(vector<int>& nums) {
        // level 0
        for (int i = 0; i < n; i++) {
            mn[i][0] = nums[i];
            mx[i][0] = nums[i];
        }

        // Rest of the levels
        for (int j = 1; j < K; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);

                mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

public:
    SparseTable(vector<int>& nums) {
        n = nums.size();

        K = __lg(n) + 1;

        mn.assign(n, vector<int>(K));
        mx.assign(n, vector<int>(K));

        build(nums);
    }

    int value(int l, int r) { return rangeMax(l, r) - rangeMin(l, r); }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        SparseTable st(nums);

        // {value, l, r}
        priority_queue<array<int, 3>> pq;

        for (int l = 0; l < n; l++) {
            int val = st.value(l, n - 1);

            pq.push({ val, l, n - 1 });
        }

        long long ans = 0;

        while (k--) {
            auto [val, l, r] = pq.top();
            pq.pop();

            ans += val;

            if (r > l) {
                int nextVal = st.value(l, r - 1);

                pq.push({ nextVal, l, r - 1 });
            }
        }

        return ans;
    }
};