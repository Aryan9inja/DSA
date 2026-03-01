For optimization in N-Queen problem, we can use three maps to keep track of the columns, and the two diagonals (main diagonal and anti-diagonal) where queens are already placed. This way, we can quickly check if placing a queen in a particular position is valid without having to iterate through the entire board.

In my code I had used the isSafe function to check if placing a queen in a particular position is valid. However, this function iterates through the entire board to check for conflicts, which can be inefficient. Instead, we can use three sets to keep track of the columns, main diagonals, and anti-diagonals where queens are already placed.

Here are the three maps we can use:
1. `columns`: A set to keep track of the columns where queens are already placed.
2. `main_diagonals`: A set to keep track of the main diagonals where queens are already placed. The main diagonal can be identified by the difference between the row and column with (n-1 + (i - j)). where n is the size of the board, i is the row index, and j is the column index.
3. `anti_diagonals`: A set to keep track of the anti-diagonals where queens are already placed. The anti-diagonal can be identified by the sum of the row and column indices (i + j).