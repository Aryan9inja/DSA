#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0, counter = 0;

        for (string& event : events) {
            if (event == "W") {
                counter++;
                if (counter == 10) return { score, counter };
            }
            else if (event == "WD") score++;
            else if (event == "NB") score++;
            else {
                score += event[0] - '0';
            }
        }
        return { score, counter };
    }
};