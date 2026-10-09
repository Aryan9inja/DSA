#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperation(int n) {
        int cnt = 0;
        while (n != 0) {
            if (n % 2 == 0)
                n /= 2;
            else
                n--;

            cnt++;
        }
        return cnt;
    }
};
