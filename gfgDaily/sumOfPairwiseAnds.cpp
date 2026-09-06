#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long pairAndSum(vector<int>& arr) {
        long long ans = 0;

        int n = arr.size();

        for (int i = 0; i < 32; i++) {
            // Count number of elements with i'th bit set
            long long k = 0;
            for (int j = 0; j < n; j++)
                if ((arr[j] & (1LL << i)))
                    k++;

            // There are k set bits, means k(k-1)/2 pairs.
            // Every pair adds 2^i to the answer. Therefore,
            // we add "2^i * [k*(k-1)/2]" to the answer.
            ans += (1LL << i) * (k * (k - 1) / 2);
        }

        return ans;
    }
};
