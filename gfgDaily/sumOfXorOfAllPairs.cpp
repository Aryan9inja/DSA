#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        // Think Bitwise
        // Each bit will constitue if 1^0 or 0^1
        // So we calculate:
        // a = number of 1 bits at a position
        // b = number of 0 bits at a position
        // a*b = number of distinct combination of 0 and 1
        // a*b*2^i = contribution at place i {i is place of bit right to left}
        
        long long sum = 0;
        
        // int is 32 bits long
        for(int i=0; i<32; i++){
            int a = 0, b = 0;
            
            for(int j=0; j<arr.size(); j++){
                if((arr[j]>>i)&1) a++;
                else b++;
            }
            sum += (long long)a*b*(1<<i);
        }
        return sum;
    }
};