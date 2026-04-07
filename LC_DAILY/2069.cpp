#include <string>
#include <vector>
using namespace std;

class Robot {
    int maxX;
    int maxY;
    int perimeter;
    int dist = 0;
    bool moved = false;

public:
    Robot(int width, int height) {
        maxX = width - 1;
        maxY = height - 1;
        perimeter = 2 * (maxX + maxY);
    }

    void step(int num) {
        if (num == 0) {
            return;
        }

        if (perimeter == 0) {
            return;
        }

        moved = true;
        dist = (dist + (num % perimeter)) % perimeter;
    }

    vector<int> getPos() {
        if (perimeter == 0 || dist == 0) {
            return { 0, 0 };
        }

        if (dist <= maxX) {
            return { dist, 0 };
        }

        if (dist <= maxX + maxY) {
            return { maxX, dist - maxX };
        }

        if (dist <= 2 * maxX + maxY) {
            return { maxX - (dist - (maxX + maxY)), maxY };
        }

        return { 0, maxY - (dist - (2 * maxX + maxY)) };
    }

    string getDir() {
        if (perimeter == 0) {
            return "East";
        }

        if (dist == 0) {
            return moved ? "South" : "East";
        }

        if (dist <= maxX) {
            return "East";
        }

        if (dist <= maxX + maxY) {
            return "North";
        }

        if (dist <= 2 * maxX + maxY) {
            return "West";
        }

        return "South";
    }
};