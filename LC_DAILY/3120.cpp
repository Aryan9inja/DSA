#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> freqSmall(26,0);
        vector<int> freqBig(26,0);

        for(char c : word){
            if(c >='A' && c <= 'Z'){
                freqBig[c-'A']++;
            }
            else{
                freqSmall[c-'a']++;
            }
        }

        int cnt = 0;
        for(int i=0; i<26; i++){
            if(freqBig[i]>0 && freqSmall[i]>0){
                cnt++;
            }
        }

        return cnt;
    }
};