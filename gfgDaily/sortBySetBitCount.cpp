#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int countSetBits(int n) {
        int count = 0;
        while (n > 0) {
            if (n & 1) count++;
            n >>= 1;
        }
        return count;
    }
    
public:
    vector<int> sortBySetBitCount(vector<int>& arr) {
        // stable_sort(arr.begin(), arr.end(), [this](int a, int b) {
        //     int a_bit = countSetBits(a);
        //     int b_bit = countSetBits(b);
        //     return a_bit > b_bit;
        // });
        // return arr;
        
        stable_sort(arr.begin(), arr.end(), [](int a, int b) {
            return __builtin_popcount(a) > __builtin_popcount(b);
        });
        return arr;
    }
};   