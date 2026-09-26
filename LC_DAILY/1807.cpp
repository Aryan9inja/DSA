#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> kMap;

        for (auto& k : knowledge) {
            string key = k[0];
            string value = k[1];

            kMap[key] = value;
        }

        string ans = "";
        for (char& c : s) {
            if (c == '(' || isalpha(c))
                ans.push_back(c);

            else {
                string temp = "";
                while (ans.back() != '(') {
                    temp += ans.back();
                    ans.pop_back();
                }
                ans.pop_back();

                reverse(temp.begin(), temp.end());

                if (!kMap.count(temp)) {
                    ans += '?';
                }
                else {
                    ans.append(kMap[temp]);
                }
            }
        }

        return ans;
    }
};