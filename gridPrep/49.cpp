#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // O(n*str.len*log(str.len))
    /*
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (auto x : strs) {
            string word = x;
            sort(word.begin(), word.end());
            mp[word].push_back(x);
        }

        vector<vector<string>> ans;
        for (auto x : mp) {
            ans.push_back(x.second);
        }
        return ans;
    }
    */

    // O(n*str.len)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string& word : strs) {
            vector<int> freq(26, 0);

            for (char c : word) {
                freq[c - 'a']++;
            }

            string key = "";
            for (int count : freq) {
                key += to_string(count) + "#";
            }

            mp[key].push_back(word);
        }

        vector<vector<string>> result;
        for (auto& pair : mp) {
            result.push_back(pair.second);
        }

        return result;
    }
};