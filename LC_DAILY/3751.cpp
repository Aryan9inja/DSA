#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solveDig(int num) {
        if (num < 101) return 0;

        int prev = num % 10;
        num /= 10;
        int curr = num % 10;
        num /= 10;

        int cnt = 0;
        while (num > 0) {
            int next = num % 10;
            num /= 10;

            if (curr > next && curr > prev) cnt++;
            else if (curr < next && curr < prev) cnt++;

            prev = curr;
            curr = next;
        }

        return cnt;
    }

    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for (int i = num1; i <= num2; i++) {
            ans += solveDig(i);
        }

        return ans;
    }
};