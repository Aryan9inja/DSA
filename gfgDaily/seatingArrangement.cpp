#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canSeatAllPeople(int k, vector<int>& seats) {
        int n = seats.size();
        int available_seats = 0;

        for (int i = 0; i < n; i++) {
            int prev = i == 0 ? 0 : seats[i - 1];
            int next = i == n - 1 ? 0 : seats[i + 1];

            if (prev + next + seats[i] == 0) {
                available_seats++;
                i++;
            }
        }

        return available_seats >= k;
    }
};
