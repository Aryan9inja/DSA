#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int isPallindrome(long long int N) {
        // O(log(n)) and O(log(n))
        /*
        string binary = "";
        
        while(N>0){
            if(N&1) binary+='1';
            else binary+='0';
            N>>=1;
        }
        
        int i=0;
        int j=binary.length()-1;
        
        while(i<j){
            if(binary[i]!=binary[j]) return 0;
            i++;
            j--;
        }
        
        return 1;
        */
        
        // O(log(n)) and O(1)
        long long int rev = 0, temp = N;
        
        while(temp>0){
            rev = (rev<<1) | (temp&1);
            temp>>=1;
        }
        
        return N==rev;
    }
};