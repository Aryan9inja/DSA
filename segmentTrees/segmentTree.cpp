#include <iostream>
#include <vector>

using namespace std;

vector<int> sourceData;
vector<int> segmentTree;

/**
 * @brief Builds the Segment Tree recursively.
 * @param node The current index in the segmentTree array.
 * @param start The starting index of the range in sourceData.
 * @param end The ending index of the range in sourceData.
 */
void buildTree(int node, int start, int end) {
    // Block 1: Base Case
    // If start == end, we've reached a leaf node representing a single element.
    if (start == end) {
        segmentTree[node] = sourceData[start];
        return;
    }

    // Block 2: Recursive Step
    // Divide the current range into two halves.
    int mid = start + (end - start) / 2;

    // Build the left child (index 2*node) and right child (index 2*node + 1).
    buildTree(2 * node, start, mid);
    buildTree(2 * node + 1, mid + 1, end);

    // Block 3: Internal Node Merging
    // The value of the parent node is the sum of its two children.
    segmentTree[node] = segmentTree[2 * node] + segmentTree[2 * node + 1];
}

/**
 * @brief Updates a specific index in the source array and reflects changes in the tree.
 * @param delta The value to add to the existing element.
 */
void updatePoint(int node, int start, int end, int targetIdx, int delta) {
    // Block 1: Leaf Update
    if (start == end) {
        sourceData[targetIdx] += delta;
        segmentTree[node] += delta;
        return;
    }

    // Block 2: Determine which child to visit
    int mid = start + (end - start) / 2;
    if (targetIdx <= mid) {
        updatePoint(2 * node, start, mid, targetIdx, delta);
    } else {
        updatePoint(2 * node + 1, mid + 1, end, targetIdx, delta);
    }

    // Block 3: Post-update Recalculation
    // After the child is updated, update the current parent node.
    segmentTree[node] = segmentTree[2 * node] + segmentTree[2 * node + 1];
}

/**
 * @brief Queries the sum within a specific range [queryL, queryR].
 */
int queryRange(int node, int start, int end, int queryL, int queryR) {
    // Block 1: Out of Range
    // If the current node's range is completely outside the query range.
    if (queryR < start || end < queryL) {
        return 0;
    }

    // Block 2: Completely Within Range
    // If the current node's range is entirely inside the query range.
    if (queryL <= start && end <= queryR) {
        return segmentTree[node];
    }

    // Block 3: Partial Overlap
    // Query both children and combine their results.
    int mid = start + (end - start) / 2;
    int leftSum = queryRange(2 * node, start, mid, queryL, queryR);
    int rightSum = queryRange(2 * node + 1, mid + 1, end, queryL, queryR);

    return leftSum + rightSum;
}

int main() {
    sourceData = { 0, 1, 3, 5, -2, 3 };
    int n = sourceData.size();

    // Standard practice is to size the tree to 4*n to avoid overflow.
    segmentTree.assign(4 * n, 0);

    buildTree(1, 0, n - 1);

    cout << "Initial Sum (range 0-4): " << queryRange(1, 0, n - 1, 0, 4) << endl;

    // Update index 1 by adding 100
    updatePoint(1, 0, n - 1, 1, 100);
    cout << "After update, Sum (range 1-3): " << queryRange(1, 0, n - 1, 1, 3) << endl;

    return 0;
}