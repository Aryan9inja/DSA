# Kirchoff's Matrix Tree Theorem
Kirchoff's Matrix Tree Theorem states that the number of spanning trees in a graph can be calculated using the determinant of a matrix derived from the graph's Laplacian matrix.

## Laplacian Matrix
The Laplacian matrix \( L \) of a graph \( G \) with \( n \) vertices is defined as:
- \( L[i][i] = \) degree of vertex \( i \)
- \( L[i][j] = -1 \) if there is an edge between vertices \( i \) and \( j \)
- \( L[i][j] = 0 \) if there is no edge between vertices \( i \) and \( j \)

## Number of Spanning Trees
To find the number of spanning trees in a graph using Kirchoff's Matrix Tree Theorem, we can follow these steps:1. Construct the Laplacian matrix \( L \) of the graph.
2. Remove any one row and the corresponding column from the Laplacian matrix to form a new matrix \( L' \).
3. Calculate the determinant of the resulting matrix \( L' \). The absolute value of this determinant gives the number of spanning trees in the graph.

## Example:
Graph with adjacency list:
```
[[0,1,1,1],
 [1,0,0,1],
 [1,0,0,1],
 [1,1,1,0]]
```
1. Construct the Laplacian matrix \( L \):
```L = 
     [[3, -1, -1, -1],
     [-1, 2, 0, -1],
     [-1, 0, 2, -1],
     [-1, -1, -1, 3]]
```
2. Remove the first row and column to get \( L' \):
```L' = 
      [[2, 0, -1],
      [0, 2, -1],
      [-1, -1, 3]]
```
3. Calculate the determinant of \( L' \):
```det(L') = 2 * (2 * 3 - (-1) * (-1)) - 0 * (0 * 3 - (-1) * (-1)) + (-1) * (0 * (-1) - 2 * (-1)) = 2 * (6 - 1) + 0 + (-1) * (0 + 2) = 2 * 5 - 2 = 10 - 2 = 8```

Thus, the number of spanning trees in the graph is 8.

Refer to [Code using C++](../gfgDaily/countSpanningTreesInGraph.cpp) for an implementation of Kirchoff's Matrix Tree Theorem.