#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string reverseWords(string &s) {
        string temp = "";
        string ans = "";
        
        for(int i=s.length()-1; i>=0; i--){
            if(s[i]=='.'){
                if (!temp.empty()) {
                    reverse(temp.begin(), temp.end());
                    if (!ans.empty()) ans += ".";
                    ans += temp;
                    temp = "";
                }
            }
            else{
                temp.push_back(s[i]);
            }
        }
        
        if (!temp.empty()) {
            reverse(temp.begin(), temp.end());
            if (!ans.empty()) ans += ".";
            ans += temp;
        }
        return ans;
    }
};