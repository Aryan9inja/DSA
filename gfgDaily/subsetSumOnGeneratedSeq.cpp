#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& arr, int s, int x) {
        int n = arr.size();

        vector<int> seq;
        seq.reserve(n + 1);
        seq.push_back(s);

        for (int& a : arr) {
            int sum = s + a;
            seq.push_back(sum);
            s += sum;
        }

        // This only works because the sequence is super increasing
        // Each element is greater than sum of all the prev elements
        long long target = x;

        for (int i = n; i >= 0; i--) {
            if (seq[i] <= target) {
                target -= seq[i];
            }
        }

        return target == 0;
    }
};
