#include<bits/stdc++.h>
using namespace std;

class SolutionNaive {
  public:
    int minSteps(int m, int n, int d) {
        if (d > max(m, n)) return -1;
        
        // Each vector will have
        // [0] - state of jug 1
        // [1] - state of jug 2
        // [2] - number of steps
        queue<vector<int>> q;
        
        // A visited state manager
        vector<vector<bool>> visited(m+1, vector<bool>(n+1, false));
        
        // Initialize the queue with starting state
        q.push({0,0,0});
        visited[0][0] = true;
        
        // Do BFS to find shortest path
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            int jug1 = front[0];
            int jug2 = front[1];
            int steps = front[2];
            
            // check if we have answers
            if (jug1 == d || jug2 == d) return steps;
            
            // Add every state transition into queue
            // 1. Fill jug 1
            if(!visited[m][jug2]){
                q.push({m, jug2, steps+1});
                visited[m][jug2] = true;
            }
            
            // 2. Fill jug 2
            if(!visited[jug1][n]){
                q.push({jug1, n, steps+1});
                visited[jug1][n] = true;
            }
            
            // 3. Empty jug 1
            if(!visited[0][jug2]){
                q.push({0, jug2, steps+1});
                visited[0][jug2] = true;
            }
            
            // 4. Empty jug 2
            if(!visited[jug1][0]){
                q.push({jug1, 0, steps+1});
                visited[jug1][0] = true;
            }
            
            // 5. Fill jug 1 with jug 2
            int fill1with2 = min(jug2, m-jug1);
            if(!visited[jug1 + fill1with2][jug2 - fill1with2]){
                q.push({jug1 + fill1with2, jug2 - fill1with2, steps+1});
                visited[jug1 + fill1with2][jug2 - fill1with2] = true;
            }
            
            // 6. Fill jug 2 with jug 1
            int fill2with1 = min(jug1, n-jug2);
            if(!visited[jug1 - fill2with1][jug2 + fill2with1]){
                q.push({jug1 - fill2with1, jug2 + fill2with1, steps+1});
                visited[jug1 - fill2with1][jug2 + fill2with1] = true;
            }
        }
        
        return -1;
    }
};

class Solution {
  public:
    int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

/* fromCap -- Capacity of jug from which
              water is poured
   toCap   -- Capacity of jug to which
              water is poured
   d       -- Amount to be measured */
int pour(int fromCap, int toCap, int d)
{
    int from = fromCap, to = 0;
    
    // initial fill
    int step = 1; 
    
    // Break the loop when either of the two
    // jugs has d litre water
    while (from != d && to != d)
    {
        int temp = min(from, toCap - to);

        to += temp;
        from -= temp;
        step++;

        if (from == d || to == d)
            break;

        // refill source
        if (from == 0)
        {
            from = fromCap;
            step++;
        }
        
        // empty destination
        if (to == toCap)
        {
            to = 0;
            step++;
        }
    }
    return step;
}

// Returns minimum steps required
int minSteps(int m, int n, int d)
{
    // To make sure that m is smaller than n
    if (m > n)
        swap(m, n);
    
    // If d > n, it is not possible to measure the water
    if (d > n)
        return -1;

    // If gcd of m and n does not divide d
    // then solution is not possible
    if (d % gcd(m, n) != 0)
        return -1;

    // Try both directions and take minimum:
    // 1. Pour from n to m
    // 2. Pour from m to n
    return min(pour(n, m, d), pour(m, n, d));
}
};