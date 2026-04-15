#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        // int ans = INT_MAX;

        // // check forward
        // int currIndex = startIndex;
        // int step = 0;
        // do {
        //     if (words[currIndex] == target) {
        //         ans = min(ans, step);
        //         break;
        //     }
        //     currIndex = (currIndex + 1) % words.size();
        //     step++;
        // }while(currIndex != startIndex);

        // // check backward
        // currIndex = startIndex;
        // step = 0;
        // do {
        //     if (words[currIndex] == target) {
        //         ans = min(ans, step);
        //         break;
        //     }
        //     currIndex = (currIndex - 1 + words.size()) % words.size();
        //     step++;
        // }while(currIndex != startIndex);

        // return ans == INT_MAX ? -1 : ans;

        int n = words.size(), ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int dif = abs(i - startIndex);
                ans = min(ans, min(dif, n - dif));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};