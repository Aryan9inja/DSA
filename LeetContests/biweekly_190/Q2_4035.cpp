#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        auto countSplits = [](vector<int>& arr) -> int {
            int m = arr.size();
            if (m <= 1) return 0;

            vector<int> prefGcd(m), suffGcd(m);

            prefGcd[0] = arr[0];
            for (int i = 1; i < m; i++) {
                prefGcd[i] = gcd(prefGcd[i - 1], arr[i]);
            }

            suffGcd[m - 1] = arr[m - 1];
            for (int i = m - 2; i >= 0; i--) {
                suffGcd[i] = gcd(suffGcd[i + 1], arr[i]);
            }

            int valid = 0;
            for (int i = 0; i < m - 1; i++) {
                if (prefGcd[i] == suffGcd[i + 1]) {
                    valid++;
                }
            }

            return valid;
            };

        int ans = countSplits(nums);
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            temp.reserve(n - 1);
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    temp.push_back(nums[j]);
                }
            }

            ans = max(ans, countSplits(temp));
        }

        return ans;
    }
};