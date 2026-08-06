#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countMinOperations(vector<int>& arr) {
        int operations = 0;
        int n = arr.size();

        while (true) {
            bool allZero = true;
            for (int x : arr) {
                if (x > 0) {
                    allZero = false;
                    break;
                }
            }
            if (allZero)
                break;

            bool anyOdd = false;
            for (int& x : arr) {
                if (x % 2 != 0) {
                    anyOdd = true;
                    x--; // Reverse of increment
                    operations++;
                }
            }

            if (!anyOdd) {
                for (int& x : arr) {
                    x /= 2;
                }
                operations++;
            }
        }
        return operations;
    }
};
