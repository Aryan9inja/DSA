#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int totalOnes = 0;
        for (char ch : s) {
            if (ch == '1') {
                totalOnes++;
            }
        }

        // Pad string with boundary '1's to simplify edge-case parsing
        string paddedStr = "1" + s + "1";
        int strLength = paddedStr.size();
        int index = 0;

        int maxActiveSections = totalOnes;

        // Skip leading '1's
        while (index < strLength && paddedStr[index] == '1') {
            index++;
        }

        // Count length of the first block of '0's
        int leftZerosCount = 0;
        while (index < strLength && paddedStr[index] == '0') {
            leftZerosCount++;
            index++;
        }

        while (index < strLength) {
            // Count length of the middle block of '1's
            int middleOnesCount = 0;
            while (index < strLength && paddedStr[index] == '1') {
                middleOnesCount++;
                index++;
            }

            if (middleOnesCount == 0) {
                break;
            }

            // Count length of the right block of '0's
            int rightZerosCount = 0;
            while (index < strLength && paddedStr[index] == '0') {
                rightZerosCount++;
                index++;
            }

            if (rightZerosCount == 0) {
                break;
            }

            maxActiveSections =
                max(maxActiveSections,
                    totalOnes + leftZerosCount + rightZerosCount);

            // Slide window: current right block of zeros becomes the next left
            // block
            leftZerosCount = rightZerosCount;
        }

        return maxActiveSections;
    }
};