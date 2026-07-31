#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    int minimumPushes(string word) {
        int n = word.size();

        vector<int> freq(26, 0);
        for (char& c : word) {
            freq[c - 'a']++;
        }

        // freq, char
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i])
                pq.push({freq[i], i});
        }

        int counter = 0;
        int ans = 0;
        while (!pq.empty()) {
            auto [f, c] = pq.top();
            pq.pop();

            ans += (counter / 8 + 1)*f;
            counter++;
        }

        return ans;
    }
    */

    int minimumPushes(string word) {
        int n = word.size();

        vector<int> freq(26, 0);
        for (char& c : word) {
            freq[c - 'a']++;
        }

        sort(freq.begin(), freq.end(), greater<int>());

        int counter = 0;
        int ans = 0;
        for (int& f : freq) {
            ans += (counter / 8 + 1) * f;
            counter++;
        }

        return ans;
    }
};