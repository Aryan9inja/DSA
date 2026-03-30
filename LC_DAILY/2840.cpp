#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        if(s1==s2) return true;

        unordered_map<char, int> odd1;
        unordered_map<char, int> odd2;
        unordered_map<char, int> even1;
        unordered_map<char, int> even2;

        for(int i=0; i<s1.length(); i++){
            if(i&1){
                odd1[s1[i]]++;
                odd2[s2[i]]++;
            }
            else{
                even1[s1[i]]++;
                even2[s2[i]]++;
            }
        }

        if(odd1 == odd2 && even1 == even2){
            return true;
        }
        return false;
    }
};