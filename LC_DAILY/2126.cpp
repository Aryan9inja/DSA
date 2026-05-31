#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long comp = mass;
        sort(asteroids.begin(), asteroids.end());

        for (const int& a : asteroids) {
            if (a > comp) {
                return false;
            }
            comp += a;
        }

        return true;
    }
};