#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> mx(n);
        mx[0] = nums[0];
        for (int i = 1; i < n; i++) {
            mx[i] = max(nums[i], mx[i - 1]);
        }

        vector<int> prefGcd(n);
        for (int i = 0; i < n; i++) {
            prefGcd[i] = gcd(nums[i], mx[i]);
        }

        sort(prefGcd.begin(), prefGcd.end());

        long long ans = 0;
        int i = 0;
        int j = n - 1;

        while (i < j) {
            ans += gcd(1LL * prefGcd[i], 1LL * prefGcd[j]);
            i++;
            j--;
        }

        return ans;
    }
};