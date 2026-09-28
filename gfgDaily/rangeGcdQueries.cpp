#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    int getMid(int s, int e) {
        return s + (e - s) / 2;
    }

    int buildSegmentTree(vector<int>& arr, int ss, int se, vector<int>& st, int si) {
        if (ss == se) {
            st[si] = arr[ss];
            return arr[ss];
        }
        int mid = getMid(ss, se);
        st[si] = gcd(buildSegmentTree(arr, ss, mid, st, si * 2 + 1),
            buildSegmentTree(arr, mid + 1, se, st, si * 2 + 2));
        return st[si];
    }

    int findGcd(int ss, int se, int qs, int qe, int si, vector<int>& st) {
        if (ss > qe || se < qs)
            return 0;
        if (qs <= ss && qe >= se)
            return st[si];
        int mid = getMid(ss, se);
        return gcd(findGcd(ss, mid, qs, qe, 2 * si + 1, st), findGcd(mid + 1, se, qs, qe, 2 * si + 2, st));
    }

    void updateValueUtil(int ss, int se, int index, int new_val, int si, vector<int>& st) {
        if (index < ss || index > se)
            return;
        if (ss == se) {
            st[si] = new_val;
            return;
        }
        int mid = getMid(ss, se);
        if (index <= mid)
            updateValueUtil(ss, mid, index, new_val, 2 * si + 1, st);
        else
            updateValueUtil(mid + 1, se, index, new_val, 2 * si + 2, st);
        st[si] = gcd(st[2 * si + 1], st[2 * si + 2]);
    }

    void updateValue(int index, int new_val, vector<int>& arr, vector<int>& st, int n) {
        arr[index] = new_val;
        updateValueUtil(0, n - 1, index, new_val, 0, st);
    }

    vector<int> processQueries(vector<int>& arr, vector<vector<int>>& q) {
        int n = arr.size();
        int x = 2 * (int)pow(2, ceil(log2(n))) - 1;
        vector<int> st(x);
        buildSegmentTree(arr, 0, n - 1, st, 0);

        vector<int> result;
        for (auto& query : q) {
            int type = query[0];
            if (type == 1) {
                int index = query[1];
                int new_val = query[2];
                updateValue(index, new_val, arr, st, n);
            }
            else {
                int l = query[1];
                int r = query[2];
                result.push_back(findGcd(0, n - 1, l, r, 0, st));
            }
        }
        return result;
    }
};
