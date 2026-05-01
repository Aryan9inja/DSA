#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0;
        int j = n - 1;

        while (i < j) {
            int sum = numbers[i] + numbers[j];

            if (target < sum) j--;
            if (target > sum) i++;

            if (target == sum) break;
        }

        return { i + 1, j + 1 };
    }
};