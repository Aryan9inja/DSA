#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Finds the kth smallest element in an unsorted array.
     * Time Complexity: O(N log k) where N is the size of the array.
     * Space Complexity: O(k) to store the elements in the priority queue.
     */
    int kthSmallest(vector<int> &arr, int k) {
        // We use a Max-Heap (priority_queue in C++ is a Max-Heap by default).
        // It keeps the largest element of the current 'k' elements at the top.
        priority_queue<int> pq;

        // Step 1: Push the first 'k' elements of the array into the Max-Heap.
        // Building the initial heap takes O(k log k).
        for(int i = 0; i < k; i++) {
            pq.push(arr[i]);
        }
        
        // Step 2: Iterate through the remaining elements (from index k to N-1).
        for(int i = k; i < arr.size(); i++) {
            // If the current element is smaller than the largest element in our heap:
            // It means the current pq.top() cannot be the kth smallest element.
            if(arr[i] < pq.top()) {
                pq.pop();           // Remove the current largest among the k elements
                pq.push(arr[i]);    // Insert the smaller candidate
            }
        }
        
        // After processing the whole array, the Max-Heap contains the k smallest 
        // elements of the array. The largest of these k elements (the top) 
        // is exactly the kth smallest element overall.
        return pq.top();
    }
};