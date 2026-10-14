#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) {
            return "";
        }

        int quotient = sum / 9;
        int remainder = sum % 9;

        string ans;
        ans.reserve(num);

        ans.append(quotient, '9');
        if (remainder) {
            ans.push_back('0' + remainder);
        }

        ans.append(num - quotient - (remainder > 0), '0');

        return ans;
    }
};