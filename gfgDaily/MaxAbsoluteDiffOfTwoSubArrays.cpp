#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
	vector<int> buildLeftMax(vector<int> &arr)
	{
		int n = arr.size();
		
		vector<int> leftMax(n);
		
		int curr = arr[0];
		int best = arr[0];
		
		leftMax[0] = best;
		
		for (int i = 1; i < n; i++)
			{
			
			// Apply Kadane's algorithm
			curr = max(arr[i], curr + arr[i]);
			
			// Update best maximum subarray sum seen so far
			best = max(best, curr);
			
			leftMax[i] = best;
		}
		
		return leftMax;
	}
	
	// Function to build maximum subarray sums from right to left
	// rightMax[i] stores the maximum subarray sum in arr[i...n-1]
	vector<int> buildRightMax(vector<int> &arr)
	{
		int n = arr.size();
		
		vector<int> rightMax(n);
		
		int curr = arr[n - 1];
		int best = arr[n - 1];
		
		rightMax[n - 1] = best;
		
		for (int i = n - 2; i >= 0; i--)
			{
			
			// Apply Kadane's algorithm in reverse direction
			curr = max(arr[i], curr + arr[i]);
			
			// Update best maximum subarray sum seen so far
			best = max(best, curr);
			
			rightMax[i] = best;
		}
		
		return rightMax;
	}
	
	int maxDiffSubArrays(vector<int> &arr)
	{
		int n = arr.size();
		
		// Maximum subarray sums on left and right side
		vector<int> leftMax = buildLeftMax(arr);
		vector<int> rightMax = buildRightMax(arr);
		
		// Create inverted array to obtain minimum subarray sums
		vector<int> inverted(arr);
		
		for (int &x : inverted)
			x = -x;
		
		// Maximum subarray on inverted array corresponds
		// to minimum subarray on original array
		vector<int> leftMin = buildLeftMax(inverted);
		vector<int> rightMin = buildRightMax(inverted);
		
		// Convert values back to minimum subarray sums
		for (int &x : leftMin)
			x = -x;
		
		for (int &x : rightMin)
			x = -x;
		
		int res = INT_MIN;
		
		// Try every possible partition point
		for (int i = 0; i < n - 1; i++)
			{
			
			// Maximum subarray on left and minimum subarray on right
			int option1 = abs(leftMax[i] - rightMin[i + 1]);
			
			// Minimum subarray on left and maximum subarray on right
			int option2 = abs(leftMin[i] - rightMax[i + 1]);
			
			// Update answer
			res = max(res, max(option1, option2));
		}
		
		return res;
	}
};
