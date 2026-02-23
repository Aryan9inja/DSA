// Include necessary libraries
#include<queue>
#include<bits/stdc++.h>
using namespace std;

// Helper function to determine the relative sizes of two heaps
// Returns 0 if equal, 1 if a > b, -1 if a < b
int signum(int a, int b){
	if(a==b) return 0;
	else if(a>b) return 1;
	else return -1;
}

// Function to process a new element and update the running median
// maxi: max-heap for the lower half
// mini: min-heap for the upper half
// median: current median (passed by reference)
void getMedian(int element, priority_queue<int> &maxi,
				priority_queue<int, vector<int>, greater<int>> &mini,
				int &median){
	switch(signum(maxi.size(), mini.size())){
		case 0:
			// Both heaps are of equal size
			// Insert into appropriate heap and update median
			if(element>median){
				mini.push(element);
				median=mini.top();
			}
			else{
				maxi.push(element);
				median=maxi.top();
			}
			break;

		case 1:
			// max-heap has more elements
			if(element>median){
				mini.push(element);
				// Median is average of tops of both heaps
				median=(mini.top()+maxi.top())/2;
			}
			else{
				// Move top of max-heap to min-heap, insert new element in max-heap
				mini.push(maxi.top());
				maxi.pop();
				maxi.push(element);
				median=(mini.top()+maxi.top())/2;
			}
			break;

		case -1:
			// min-heap has more elements
			if(element>median){
				// Move top of min-heap to max-heap, insert new element in min-heap
				maxi.push(mini.top());
				mini.pop();
				mini.push(element);
				median=(mini.top()+maxi.top())/2; 	
			}
			else{
				maxi.push(element);
				median=(mini.top()+maxi.top())/2;
			}
			break;
	}
}

// Main function to return a vector of running medians for the input array
vector<int> findMedian(vector<int> &arr, int n){
	vector<int> ans;

	// maxHeap: stores the smaller half (max at top)
	priority_queue<int> maxHeap;
	// minHeap: stores the larger half (min at top)
	priority_queue<int, vector<int>, greater<int>> minHeap;
	int median =0; // Initial median

	for(int i=0;i<n;i++){
		// Insert new element and update median
		getMedian(arr[i], maxHeap, minHeap, median);
		ans.push_back(median);
	}
	return ans;
}
