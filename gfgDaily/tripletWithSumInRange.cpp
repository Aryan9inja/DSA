#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTripletsLessThanEqualTo(vector<int>& arr, int x) {
        int n = arr.size();

        int cnt = 0;

        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = arr[i] + arr[j] + arr[k];

                if (sum > x) {
                    k--;
                }
                else {
                    cnt += (k - j);
                    j++;
                }
            }
        }
        return cnt;
    }

    int countTriplets(vector<int>& arr, int l, int r) {
        sort(arr.begin(), arr.end());

        int res = countTripletsLessThanEqualTo(arr, r)
            - countTripletsLessThanEqualTo(arr, l - 1);

        return res;
    }
};
