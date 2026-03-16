## Dynamic Programming
Dynamic Programming (DP) is a method for solving complex problems by breaking them down into simpler subproblems. It is particularly useful for optimization problems where the solution can be expressed as a combination of solutions to subproblems.

### Key Concepts
1. **Optimal Substructure**: A problem has an optimal substructure if an optimal solution can be constructed from optimal solutions of its subproblems. 
2. **Overlapping Subproblems**: A problem has overlapping subproblems if the same subproblems are solved multiple times. DP takes advantage of this by storing the results of subproblems to avoid redundant work.

### Approaches to Dynamic Programming
1. **Top-Down (Memoization)**: This approach involves writing the recursive solution and storing the results of subproblems in a data structure (like a dictionary or array) to avoid redundant calculations. When the same subproblem is encountered again, the stored result is returned instead of recalculating it.

2. **Bottom-Up (Tabulation)**: This approach involves solving the subproblems iteratively and storing their results in a table (usually an array). The solution to the original problem is built up from the solutions to the subproblems.

#### NOTE:
**Space Optimization**: In some cases, we can optimize the space complexity of a DP solution by only storing the necessary results instead of the entire table.