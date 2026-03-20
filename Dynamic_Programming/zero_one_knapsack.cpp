#include <bits/stdc++.h> 
using namespace std;

// -------------------- RECURSIVE --------------------
int recusrive(vector<int> &weight, vector<int> &value, int index, int capacity){
	// Base case: only 1 item (index = 0)
	if(index==0){
		// If it fits → take it
		if(weight[0]<=capacity) return value[0];
		// Else → can't take
		return 0;
	}

	// Option 1: Include current item (only if it fits)
	int include=0;
	if(weight[index]<=capacity){
		include = value[index] + recusrive(weight, value, index-1, capacity-weight[index]);
	}

	// Option 2: Exclude current item
	int exclude = recusrive(weight, value, index-1, capacity);

	// Take best of both choices
	return max(include, exclude);
}


// -------------------- MEMOIZATION --------------------
int memoization(vector<int> &weight, vector<int> &value, int index, int capacity, 
vector<vector<int>> &dp){

	// Same base case as recursion
	if(index==0){
		if(weight[0]<=capacity) return value[0];
		return 0;
	}

	// If already computed → reuse
	if(dp[index][capacity]!=-1){
		return dp[index][capacity];
	}

	// Include case
	int include=0;
	if(weight[index]<=capacity){
		include = value[index] + memoization(weight, value, index-1, capacity-weight[index], dp);
	}

	// Exclude case
	int exclude = memoization(weight, value, index-1, capacity, dp);

	// Store result
	dp[index][capacity] = max(include, exclude);
	return dp[index][capacity];
}


// -------------------- TABULATION --------------------
int tabulation(vector<int> &weight, vector<int> &value, int n, int capacity){

	// dp[index][w] = max value using items [0..index] with capacity w
	vector<vector<int>> dp(n, vector<int>(capacity+1,0));

	// Base case: fill first row (only item 0)
	for(int w=weight[0]; w<=capacity; w++){
		// If item fits → take it
		dp[0][w] = value[0];
	}

	// Build table bottom-up
	for(int index=1; index<n; index++){
		for(int w=0; w<=capacity; w++){

			// Include current item
			int include=0;
			if(weight[index]<=w){
				include = value[index] + dp[index-1][w-weight[index]];
			}

			// Exclude current item
			int exclude = dp[index-1][w];

			// Store best choice
			dp[index][w] = max(exclude, include);
		}
	}

	// Final answer at last item & full capacity
	return dp[n-1][capacity];
}


// -------------------- SPACE OPTIMIZATION (2 ARRAYS) --------------------
int spaceOptimal(vector<int> &weight, vector<int> &value, int n, int capacity){

	// prev = dp[index-1], curr = dp[index]
	vector<int> prev(capacity+1,0);
	vector<int> curr(capacity+1,0);

	// Base case (first item)
	for(int w=weight[0]; w<=capacity; w++){
		prev[w] = value[0];
	}

	// Iterate items
	for(int index=1; index<n; index++){
		for(int w=0; w<=capacity; w++){

			// Include case (use prev row)
			int include=0;
			if(weight[index]<=w){
				include = value[index] + prev[w-weight[index]];
			}

			// Exclude case
			int exclude = prev[w];

			curr[w] = max(exclude, include);
		}

		// Move curr → prev for next iteration
		prev = curr;
	}

	return prev[capacity];
}


// -------------------- SPACE OPTIMIZATION (1 ARRAY) --------------------
int spaceOptimal2(vector<int> &weight, vector<int> &value, int n, int capacity){

	// Single array DP
	vector<int> curr(capacity+1,0);

	// Base case (first item)
	for(int w=weight[0]; w<=capacity; w++){
		curr[w] = value[0];
	}

	// Iterate items
	for(int index=1; index<n; index++){

		// IMPORTANT: go RIGHT → LEFT
		// So we don't overwrite needed values
		for(int w=capacity; w>=0; w--){

			// Include case
			int include=0;
			if(weight[index]<=w){
				include = value[index] + curr[w-weight[index]];
			}

			// Exclude case (old value)
			int exclude = curr[w];

			// Update in-place
			curr[w] = max(exclude, include);
		}
	}

	return curr[capacity];
}


// -------------------- DRIVER --------------------
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){

	// return recusrive(weight, value, n-1, maxWeight);

	// vector<vector<int>> dp(n, vector<int>(maxWeight+1,-1));
	// return memoization(weight, value, n-1, maxWeight, dp);

	// return tabulation(weight, value, n, maxWeight);

	// return spaceOptimal(weight, value, n, maxWeight);

	// Best version
	return spaceOptimal2(weight, value, n, maxWeight);
}