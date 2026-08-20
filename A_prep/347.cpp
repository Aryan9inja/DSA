#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freq;

        for (const int& n : nums) {
            freq[n]++;
        }

        vector<vector<int>> bucket(n + 1);

        for (auto [num, f] : freq) {
            bucket[f].push_back(num);
        }

        vector<int> ans;
        for (int f = n; f >= 1 && ans.size() < k; f--) {
            for (int num : bucket[f]) {
                ans.push_back(num);

                if (ans.size() == k) {
                    break;
                }
            }
        }

        return ans;
    }
};