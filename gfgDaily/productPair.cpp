#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isProduct(vector<int>& arr, long long target) {
        unordered_set<long long> st;

        for (long long num : arr) {
            // Handle zero separately — no division allowed
            if (num == 0) {
                if (target == 0)
                    return true;
                continue; // 0 can never contribute to a non-zero product
            }

            if (target % num == 0) {
                long long secondNum = target / num;
                if (st.count(secondNum))
                    return true;
            }
            st.insert(num);
        }
        return false;
    }
};
