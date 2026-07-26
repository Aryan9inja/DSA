#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(int n, int s) {
        if(s>9*n) return -1;

        if(s==0) return 0;

        string ans = "";

        for(int i=0; i<n; i++){
            int digLeft = n-i-1;
            int maxPossible = 9;

            if(s-maxPossible>9*digLeft){
                maxPossible = s-9*digLeft;
            }

            if(maxPossible > s){
                maxPossible = s;
            }

            ans+=to_string(maxPossible);
            s-=maxPossible;
        }

        return stoi(ans);
    }
};