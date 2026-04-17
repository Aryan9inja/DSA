#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // O(n) - space
        /*
        int count[256] = {0};

        // Count frequency of characters
        for (int i = 0; s[i]; i++)
            count[s[i]]++;
    
        int odd = 0;
    
        // Count odd frequencies
        for (int i = 0; i < 256; i++) {
            if (count[i] % 2 != 0)
                odd++;
    
            if (odd > 1)
                return false;
        }
    
        return true;
        */
        
        // O(1) - space
        int mask = 0;

        // toggle bits
        for (int i = 0; s[i]; i++) {
            int bit = s[i] - 'a';
            mask ^= (1 << bit);
        }
    
        // check at most one bit set
        return (mask == 0) || (mask & (mask - 1)) == 0;
    }
};