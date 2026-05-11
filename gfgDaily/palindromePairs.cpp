#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(const string& s) {
        int i = 0;
        int j = s.length() - 1;

        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    bool palindromePair(vector<string>& arr) {
        unordered_map<string, int> rev;

        for (int i = 0; i < arr.size(); i++) {
            string word = arr[i];
            reverse(word.begin(), word.end());
            rev[word] = i;
        }

        for (int i = 0; i < arr.size(); i++) {
            string left = "";
            for (int j = 0; j < arr[i].length(); j++) {
                left += arr[i][j];

                string right = arr[i].substr(j + 1);

                if (!left.empty() && isPalindrome(left) && rev.count(right) && rev[right] != i) {
                    return true;
                }

                if (isPalindrome(right) && rev.count(left) && rev[left] != i) {
                    return true;
                }
            }
        }

        return false;
    }
};
