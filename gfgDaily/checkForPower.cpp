#include<bits/stdc++.h>
using namespace std;

// class Solution {
//   public:
//     bool isPower(int x, int y) {
//         // The only power of 1 is 1 itself
//         if (x == 1){
//             return (y == 1);
//         }
    
//         // If y is 1, then x^0 = 1
//         if (y == 1){
//             return true;
//         }
    
//         // Repeatedly compute power of x using squaring
//         int pow = x, i = 1;
//         while (pow < y) {
//             pow *= pow;
            
//             // track exponent growth
//             i *= 2;
//         }
    
//         if (pow == y){
//             return true;
//         }
    
//         // Apply binary search to find correct power
//         int low = x, high = pow;
//         while (low <= high) {
//             int mid = low + (high - low) / 2;
    
//             // Estimate exponent using logarithm
//             int exponent = (int)(log(mid) / log(x));
//             int result = (int)powl(x, exponent);
    
//             if (result == y)
//                 return true;
    
//             // Move search space
//             if (result < y)
//                 low = mid + 1;
//             else
//                 high = mid - 1;
//         }

//         // If no power matches
//         return false;
//     }
// };

class Solution{
public:
    bool isPower(int x, int y)
    {
        // Edge case: 1^k = 1 only
        if (x == 1)
            return y == 1;
    
        // Edge case: x^0 = 1
        if (y == 1)
            return true;
    
        // Compute logarithm
        double res = log(y) / log(x);
        
        // Compare with rounded value using a small 
        // tolerance to avoid floating point errors
        return fabs(res - round(res)) < 1e-10;
    }
};