#include<bits/stdc++.h>
using namespace std;

// class Solution {
//   public:
//     int myAtoi(string &s) {
//         string cleanS = "";
//         bool signChecked = false;
        
//         for(char c : s){
//             if((c == '+' || c == '-') && !signChecked){
//                 cleanS += c;
//                 signChecked = true;
//             }
            
//             else if(c >= '0' && c <= '9'){
//                 cleanS += c;
//                 signChecked = true;
//             }
            
//             else if(c == ' ' && !signChecked) continue;
//             else break;
//         }
        
//         long long ans = 0;
        
//         int j = 0;
//         for(int i=cleanS.length()-1; i>=0; i--){
//             if(cleanS[i]== '-' || cleanS[i]=='+') break;
//             ans += pow(10,j) * (cleanS[i] - '0');
//             j++;
//         }
        
//         if (cleanS[0] == '-') ans = -ans;
//         if (ans > 2147483647) return 2147483647;
//         if (ans < -2147483648) return -2147483648;
//         return ans;
//     }
// };

class Solution {
  public:
    int myAtoi(string &s) {
        int i = 0;
        int n = s.length();
        
        // Skip leading whitespaces
        while(i < n && s[i] == ' ') i++;
        
        // Check sign
        int sign = 1;
        if(i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // Read digits and build number
        long long ans = 0;
        while(i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');
            
            // Handle overflow early
            if(ans > 2147483647) {
                return (sign == 1) ? 2147483647 : -2147483648;
            }
            i++;
        }
        
        return sign * ans;
    }
};
