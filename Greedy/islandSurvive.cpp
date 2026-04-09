#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumDays(int S, int N, int M) {
        // 6 din ka khana - 7 din k need se bda chahiye
        if (S > 6 && N * 6 < M * 7) return -1;
        
        int sundays = S/7;
        int buyingDays = S - sundays;
        
        int FoodReq = S*M;
        
        int ans = -1;
        if(FoodReq % N == 0){
            ans = FoodReq/N;
        }
        else{
            ans = FoodReq/N + 1;
        }
        
        if(ans <= buyingDays) return ans;
        
        return -1;
    }
};