#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        vector<int> s1_freq(26, 0);
        vector<int> freq(26,0); // curr window freq

        // check s1 freq
        for(char c : s1){
            s1_freq[c-'a']++;
        }

        // check first window
        for(int i=0; i<s1.length(); i++){
            freq[s2[i]-'a']++;
        }

        // initial window check
        if(s1_freq == freq) return true;

        int i = 0;
        for(int j=s1.length(); j<s2.length(); j++){
            freq[s2[i] - 'a']--;
            freq[s2[j] - 'a']++;

            if(s1_freq == freq) return true;
            i++;
        }

        return false;
    }
};