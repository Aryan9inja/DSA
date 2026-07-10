class Solution {
  public:
    int getCount(int n)
{
    int count = 0;

    // k represents the number of elements in our consecutive sequence.
    // we need at least 2 numbers, so we start checking from k = 2.
    for (long long k = 2; ; k++)
    {
        // baseSum is the sum of the first (k-1) numbers: 1 + 2 + ... + (k-1)
        long long baseSum = (k * (k - 1)) / 2;

        // if the minimum possible sum of k elements is greater than or 
        // equal to n, no valid sequence of length k or greater can exist.
        if (baseSum >= n) {
            break; 
        }

        // if (n - baseSum) can be divided equally among the k elements,
        // it means a valid starting integer 'a' exists.
        if ((n - baseSum) % k == 0) {
            count++;
        }
    }

    return count;
}
};