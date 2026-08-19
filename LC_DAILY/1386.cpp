#include<bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    int check(const unordered_set<int>& reserved) {
        bool leftFree = true;
        bool rightFree = true;
        bool middleFree = true;

        for (int i = 2; i <= 5; ++i) {
            if (reserved.count(i)) {
                leftFree = false;
                break;
            }
        }

        for (int i = 6; i <= 9; ++i) {
            if (reserved.count(i)) {
                rightFree = false;
                break;
            }
        }

        for (int i = 4; i <= 7; ++i) {
            if (reserved.count(i)) {
                middleFree = false;
                break;
            }
        }

        if (leftFree && rightFree) {
            return 2;
        }

        if (leftFree || rightFree) {
            return 1;
        }

        if (middleFree) {
            return 1;
        }

        return 0;
    }

    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> reservations;
        for (auto res : reservedSeats) {
            int row = res[0];
            int col = res[1];

            reservations[row].insert(col);
        }

        int allocations = 0;
        for (auto& it : reservations) {
            allocations += check(it.second);
        }

        allocations += 2 * (n - reservations.size());

        return allocations;
    }
};
*/

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // Map row number to a 10-bit integer mask of reserved seats
        unordered_map<int, int> reservedMap;
        for (const auto& res : reservedSeats) {
            reservedMap[res[0]] |= (1 << res[1]);
        }

        // Bitmasks for the 3 candidate 4-seat blocks:
        // Seats 2,3,4,5 -> (1<<2)|(1<<3)|(1<<4)|(1<<5) = 0b0000111100 = 60
        // Seats 6,7,8,9 -> (1<<6)|(1<<7)|(1<<8)|(1<<9) = 0b1111000000 = 960
        // Seats 4,5,6,7 -> (1<<4)|(1<<5)|(1<<6)|(1<<7) = 0b0011110000 = 240
        const int left = 60;
        const int right = 960;
        const int middle = 240;

        int allocations = 2 * (n - reservedMap.size());

        for (const auto& [row, mask] : reservedMap) {
            bool leftFree = (mask & left) == 0;
            bool rightFree = (mask & right) == 0;
            bool middleFree = (mask & middle) == 0;

            if (leftFree && rightFree) {
                allocations += 2;
            }
            else if (leftFree || rightFree || middleFree) {
                allocations += 1;
            }
        }

        return allocations;
    }
};