#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();

        int maxi = 1;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> cnt;
            map<int, int> freqCnt;

            for (int j = i; j < n; j++) {
                int x = nums[j];

                if (cnt.count(x) > 0) {
                    int oldFreq = cnt[x];
                    freqCnt[oldFreq]--;
                    if (freqCnt[oldFreq] == 0) {
                        freqCnt.erase(oldFreq);
                    }
                }

                cnt[x]++;
                int newFreq = cnt[x];
                freqCnt[newFreq]++;

                int currLen = j - i + 1;

                if (freqCnt.size() == 1) {
                    // int uniq = freqCnt.begin()->first;
                    if (cnt.size() == 1) {
                        maxi = max(maxi, currLen);
                    }
                }
                else if (freqCnt.size() == 2) {
                    auto it = freqCnt.begin();
                    int f1 = it->first;
                    int f2 = next(it)->first;

                    if (f2 == 2 * f1) {
                        maxi = max(maxi, currLen);
                    }
                }
            }
        }
        return maxi;
    }
};