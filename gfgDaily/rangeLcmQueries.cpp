#include <bits/stdc++.h>
using namespace std;

long long gcdll(long long a, long long b) {
    if (b == 0)
        return a;
    return gcdll(b, a % b);
}

long long lcm(long long a, long long b) {
    if (a == 0 || b == 0)
        return 0;

    return (a / gcdll(a, b)) * b;
}

class SegmentTree {
private:
    vector<long long> segTree;
    vector<int> arr;
    int n;

public:
    SegmentTree(vector<int> input) {
        arr = input;
        n = arr.size();
        segTree.resize(4 * n);

        if (n > 0)
            build(0, 0, n - 1);
    }

    void build(int node, int start, int end) {
        if (start == end) {
            segTree[node] = arr[start];
            return;
        }

        int mid = start + (end - start) / 2;

        build(2 * node + 1, start, mid);
        build(2 * node + 2, mid + 1, end);

        segTree[node] =
            lcm(segTree[2 * node + 1], segTree[2 * node + 2]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            arr[idx] = val;
            segTree[node] = val;
            return;
        }

        int mid = start + (end - start) / 2;

        if (idx <= mid) {
            update(2 * node + 1, start, mid, idx, val);
        }
        else {
            update(2 * node + 2, mid + 1, end, idx, val);
        }

        segTree[node] =
            lcm(segTree[2 * node + 1], segTree[2 * node + 2]);
    }

    long long query(int node, int start, int end, int l, int r) {
        // no overlap
        if (end < l || start > r)
            return 1;

        // complete overlap
        if (start >= l && end <= r)
            return segTree[node];

        int mid = start + (end - start) / 2;

        long long left =
            query(2 * node + 1, start, mid, l, r);

        long long right =
            query(2 * node + 2, mid + 1, end, l, r);

        return lcm(left, right);
    }

    int getSize() {
        return n;
    }
};

class Solution {
public:
    vector<long long> RangeLCMQuery(
        vector<int>& arr,
        vector<vector<int>>& queries) {

        SegmentTree st(arr);

        vector<long long> result;

        int n = st.getSize();

        for (const auto& q : queries) {
            int type = q[0];

            if (type == 1) {
                int idx = q[1];
                int val = q[2];

                st.update(0, 0, n - 1, idx, val);
            }
            else {
                int l = q[1];
                int r = q[2];

                result.push_back(
                    st.query(0, 0, n - 1, l, r));
            }
        }

        return result;
    }
};