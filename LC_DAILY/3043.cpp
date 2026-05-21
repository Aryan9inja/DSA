#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> pre;

        for (int num : arr1) {
            int x = num;
            while (x) {
                pre.insert(x);
                x /= 10;
            }
        }

        int maxi = 0;
        for (int num : arr2) {
            int x = num;
            while (x) {
                if (pre.count(x)) {
                    maxi = max(maxi, x);
                    break;
                }
                x /= 10;
            }
        }

        int ans = 0;
        while (maxi) {
            ans++;
            maxi /= 10;
        }

        return ans;
    }
};