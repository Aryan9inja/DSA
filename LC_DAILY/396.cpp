#include<bits/stdc++.h>
using namespace std;

/*
    DERIVATION OF THE ROTATE FUNCTION FORMULA:

    Let S be the total sum of the array:
    S = A[0] + A[1] + A[2] + ... + A[n-1]

    Let's write out the first two rotations, F(0) and F(1):
    F(0) = 0*A[0] + 1*A[1] + 2*A[2] + ... + (n-1)*A[n-1]
    F(1) = 0*A[n-1] + 1*A[0] + 2*A[1] + ... + (n-1)*A[n-2]

    What happens when we subtract F(0) from F(1)?
    F(1) - F(0) = (1*A[0] - 0*A[0]) + (2*A[1] - 1*A[1]) + ... + (0*A[n-1] -
   (n-1)*A[n-1]) F(1) - F(0) = A[0] + A[1] + A[2] + ... + A[n-2] - (n-1)*A[n-1]

    Notice that (A[0] + A[1] + ... + A[n-2]) is just the total sum (S) minus
   A[n-1]. So we can substitute that part with (S - A[n-1]):

    F(1) - F(0) = (S - A[n-1]) - (n-1)*A[n-1]
    F(1) - F(0) = S - A[n-1] - n*A[n-1] + A[n-1]
    F(1) - F(0) = S - n*A[n-1]

    Move F(0) to the other side to isolate F(1):
    F(1) = F(0) + S - n*A[n-1]

    GENERALIZED FORMULA:
    Because this relationship holds true for any shift, we can generalize it.
    For any rotation 'i', the element that wraps around to the front is A[n-i].

    F(i) = F(i-1) + S - n * A[n-i]
*/
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long sum = 0;
        long F = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            F += (long)i * nums[i];
        }

        long ans = F;

        for (int i = 1; i < n; i++) {
            F += sum - (long)n * nums[n - i];
            ans = max(ans, F);
        }

        return (int)ans;
    }
};