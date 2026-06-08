#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // string profession(int level, int pos) {
    //     if (level == 1)
    //         return "Engineer";

    //     if (profession(level - 1, (pos + 1) / 2) == "Doctor")
    //         return (pos & 1) ? "Doctor" : "Engineer";

    //     return (pos & 1) ? "Engineer" : "Doctor";
    // }

    string profession(int level, int pos) {
        return (__builtin_popcount(pos - 1) % 2 == 0)
            ? "Engineer"
            : "Doctor";
    }
};
