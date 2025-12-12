#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printTheDiamond(int r, int c, int s)
{
    // Each diamond is 2*s x 2*s in size
    int diamondSize = 2 * s;
    
    // Total grid dimensions
    int totalRows = r * diamondSize;
    int totalCols = c * diamondSize;
    
    // Print each row of the entire grid
    for (int row = 0; row < totalRows; row++) {
        for (int col = 0; col < totalCols; col++) {
            // Find which diamond we're in
            int diamondRow = row / diamondSize;
            int diamondCol = col / diamondSize;
            
            // Find position within the current diamond
            int localRow = row % diamondSize;
            int localCol = col % diamondSize;
            
            char ch;
            
            // Determine the character based on position within diamond
            if (localRow == 0) {
                // Top row of diamond
                if (localCol == s - 1) {
                    ch = '/';
                } else if (localCol == s) {
                    ch = '\\';
                } else {
                    ch = 'e';
                }
            } else if (localRow == diamondSize - 1) {
                // Bottom row of diamond
                if (localCol == s - 1) {
                    ch = '\\';
                } else if (localCol == s) {
                    ch = '/';
                } else {
                    ch = 'e';
                }
            } else if (localRow < s) {
                // Upper half of diamond (excluding top row)
                if (localCol == s - 1 - localRow) {
                    ch = '/';
                } else if (localCol == s + localRow) {
                    ch = '\\';
                } else if (localCol > s - 1 - localRow && localCol < s + localRow) {
                    ch = 'o';
                } else {
                    ch = 'e';
                }
            } else {
                // Lower half of diamond (excluding bottom row)
                int mirrorRow = diamondSize - 1 - localRow;
                if (localCol == s - 1 - mirrorRow) {
                    ch = '\\';
                } else if (localCol == s + mirrorRow) {
                    ch = '/';
                } else if (localCol > s - 1 - mirrorRow && localCol < s + mirrorRow) {
                    ch = 'o';
                } else {
                    ch = 'e';
                }
            }
            
            cout << ch;
        }
        cout << "\n";
    }
}

int main()
{
    printTheDiamond(2,1,3);
    cout<<("\n");
    printTheDiamond(2,4,3);
    return 0;
}
