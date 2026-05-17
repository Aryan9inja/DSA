#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long power(long long x, int k, int n){
        long long res = 1;
        for(int i=0; i<k; ++i){
            if(res > n/x){
                return n+1;
            }
            res*=x;
        }
        return res;
    }
    
    int countPerfectPowers(int n, int k){
        if(n<1) return 0;

        int low = 1;
        int high = min(n, 31622);

        int ans = 0;

        while(low <= high){
            long long mid = low + (high-low)/2;
            long long p = power(mid, k, n);

            if(p<=n){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
    
    int countKthRoots(int l, int r, int k) {
        if(k==1) return r-l+1;

        int cntR = countPerfectPowers(r, k);
        int cntL = countPerfectPowers(l-1, k);

        int res = cntR - cntL;

        if(l == 0) res+=1;

        return res;
    }
};