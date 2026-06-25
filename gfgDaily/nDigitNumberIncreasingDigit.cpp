#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void generate(int remainingDigits, int currNum,
        int currDig, vector<int>& res) {
        if (remainingDigits == 0) {
            res.push_back(currNum);
            return;
        }

        for (int nextDig = currDig + 1; nextDig <= 9; nextDig++) {
            generate(remainingDigits - 1,
                currNum * 10 + nextDig, nextDig, res);
        }
    }

    vector<int> increasingNumbers(int n) {
        vector<int> res;

        if (n == 1) {
            for (int i = 0; i <= 9; i++) {
                res.push_back(i);
            }
            return res;
        }

        if (n > 9)
            return res;

        for (int firstDig = 1; firstDig <= 9; firstDig++) {
            generate(n - 1, firstDig, firstDig, res);
        }
        return res;
    }
};
