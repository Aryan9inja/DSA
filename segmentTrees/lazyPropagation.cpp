#include <iostream>
#include <vector>

using namespace std;

vector<int> tree;
vector<int> lazy;

/**
 * @brief Ensures any pending updates for a node are applied and pushed to children.
 */
void pushPendingUpdates(int node, int start, int end) {
    if (lazy[node] != 0) {
        // Apply the pending value to the current node
        // For a sum tree, the node's value increases by (range_size * lazy_value)
        tree[node] += (end - start + 1) * lazy[node];

        // If not a leaf, pass the "lazy" task down to children
        if (start != end) {
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }

        // Reset the current node's lazy flag
        lazy[node] = 0;
    }
}

/**
 * @brief Updates a range [updateL, updateR] by adding 'val'.
 */
void updateRange(int node, int start, int end, int updateL, int updateR, int val) {
    // Block 1: Resolve lazy flags before doing anything
    pushPendingUpdates(node, start, end);

    // Block 2: Out of bounds
    if (start > end || start > updateR || end < updateL) {
        return;
    }

    // Block 3: Fully within range - The "Lazy" part
    if (start >= updateL && end <= updateR) {
        tree[node] += (end - start + 1) * val;
        if (start != end) {
            lazy[2 * node + 1] += val;
            lazy[2 * node + 2] += val;
        }
        return;
    }

    // Block 4: Partial overlap - Standard recursion
    int mid = start + (end - start) / 2;
    updateRange(2 * node + 1, start, mid, updateL, updateR, val);
    updateRange(2 * node + 2, mid + 1, end, updateL, updateR, val);

    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}

/**
 * @brief Queries the sum in range [queryL, queryR].
 */
int queryRange(int node, int start, int end, int queryL, int queryR) {
    // Block 1: Resolve lazy flags first
    pushPendingUpdates(node, start, end);

    if (start > end || start > queryR || end < queryL) {
        return 0;
    }

    if (start >= queryL && end <= queryR) {
        return tree[node];
    }

    int mid = start + (end - start) / 2;
    return queryRange(2 * node + 1, start, mid, queryL, queryR) +
           queryRange(2 * node + 2, mid + 1, end, queryL, queryR);
}