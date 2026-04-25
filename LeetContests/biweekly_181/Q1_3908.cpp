#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validDigit(int n, int x) {
        // if (x == n) return true ;
        bool ans = false;
        while(n>=10){
            int dig = n%10;
            n=n/10;
            if(dig == x) ans = true;
        }
        if(n%10 == x) ans = false;
        return ans;
    }
};