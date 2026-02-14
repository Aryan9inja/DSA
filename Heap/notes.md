## Positions:
### if currentNodeIndex = i
### leftChildIndex = 2i
### rightChildIndex = 2i + 1
### parentIndex = i/2

## Max Heap:
### A binary tree where each parent node is greater than or equal to its children.
### The largest element is at the root of the tree.
### Used for implementing priority queues and heapsort.

## Min Heap:
### A binary tree where each parent node is less than or equal to its children.
### The smallest element is at the root of the tree.
### Used for implementing priority queues and heapsort.

## Operations:
### Insertion:
1. Add the new element at the end of the heap (maintaining the complete tree property).
2. "Heapify up" the new element by comparing it with its parent and swapping if necessary until the heap property is restored.
3. Time complexity: O(log n)
4. Space complexity: O(1)

### Deletion (removing the root):
1. Replace the root element with the last element in the heap.
2. Remove the last element from the heap.
3. "Heapify down" the new root element by comparing it with its children and swapping if necessary until the heap property is restored.
4. Time complexity: O(log n)
5. Space complexity: O(1)

### Additional Information:
- Heaps can be implemented using arrays, where the parent-child relationships are maintained based on the index positions.
- Heaps are commonly used in algorithms like heapsort and for implementing priority queues.
- Leaf nodes in a heap are located at the last level of the tree, and they are filled from left to right.
- Index of leaf nodes starts from n/2 + 1 to n, where n is the total number of nodes in the heap.
- Since leaf nodes do not have children, they do not need to be heapified down during deletion.
#### To heapify a tree we only need to heapify the non-leaf nodes, which are located from index 1 to n/2.