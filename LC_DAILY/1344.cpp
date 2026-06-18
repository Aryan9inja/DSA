#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minuteAngle = (360.0 / 60) * minutes;
        double hourAngle = (360.0 / 12) * (hour % 12)
            + (360.0 / (12 * 60)) * minutes;

        double diff = abs(hourAngle - minuteAngle);

        return min(diff, 360.0 - diff);
    }
};