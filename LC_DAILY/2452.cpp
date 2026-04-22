#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;

        for(string &q : queries){
            for(string &d : dictionary){
                int diff = 0;

                for(int i=0; i<q.length(); i++){
                    if(q[i]!=d[i]) diff++;
                    if(diff > 2) break;
                }

                if(diff <= 2){
                    ans.push_back(q);
                    break;   
                }
            }
        }

        return ans;
    }
};