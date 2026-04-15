#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool canFinish(int k, int h, vector<int>& piles){
        long long time = 0;
        for(int pile : piles){
            time += 1LL *(pile + k - 1) / k;
        }
        return time <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1, end = 1;
        for(int n : piles){
            end = max(end, n);
        }

        while(start <= end){
            int mid = start + (end - start)/2;

            if(canFinish(mid, h, piles)){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }

        return start;
    }
};