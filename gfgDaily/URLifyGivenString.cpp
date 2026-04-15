#include<bits/stdc++.h>
using namespace std;

// class Solution {
//   public:
//     string URLify(string &s) {
//         string space = "%20";
//         for(int i = 0; i < s.length(); i++){
//             if(s[i]==' '){
//                 s.replace(i,1,space);
//             }
//         }
//         return s;
//     }
// };

// class Solution {
//   public:
//     string URLify(string &s) {
//         string result = "";
//         for (char c : s) {
//             if (c == ' ') result += "%20";
//             else result += c;
//         }
//         return result;
//     }
// };

class Solution {
  public:
    string URLify(string &s) {
        // Pass 1: Count spaces
        int spaceCount = 0;
        int origLen = s.length();
        for (char c : s)
            if (c == ' ') spaceCount++;

        // Resize string to fit '%20' replacements
        int newLen = origLen + spaceCount * 2;
        s.resize(newLen);

        // Pass 2: Fill from the end (backwards)
        int i = origLen - 1;
        int j = newLen - 1;
        while (i >= 0) {
            if (s[i] == ' ') {
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';
            } else {
                s[j--] = s[i];
            }
            i--;
        }
        return s;
    }
};