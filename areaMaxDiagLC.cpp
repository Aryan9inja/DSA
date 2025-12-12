#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

double diag(int x, int y) {
    return sqrt(x * x + y * y);
}

int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
    int arrSize = dimensions.size();
    vector<double> diagArr;
    vector<int> areaArr;

    for (int i = 0; i < arrSize; i++) {
        diagArr.push_back(diag(dimensions[i][0], dimensions[i][1]));
        areaArr.push_back(dimensions[i][0] * dimensions[i][1]);
    }

    int maxDiag = -1;
    int cnt = 0;
    int maxDiagIndex = 0;
    for (int i = 0; i < diagArr.size(); i++) {
        if (diagArr[i] == maxDiag) {
            cnt++;
            if (cnt == 2) {
                break;
            }
        }

        else if (diagArr[i] > maxDiag) {
            maxDiagIndex = i;
            maxDiag = diagArr[i];
        }
    }

    int maxArea = -1;
    for (int i = 0; i < arrSize; i++) {
        maxArea = max(maxArea, areaArr[i]);
    }

    return cnt==2 ? maxArea : areaArr[maxDiagIndex];
}

int main() {
    vector<vector<int>> dimensions;

    vector<int> d;

    d.push_back(9);
    d.push_back(3);

    dimensions.push_back(d);

    d.pop_back();
    d.pop_back();
    d.push_back(8);
    d.push_back(6);

    dimensions.push_back(d);

    cout<<areaOfMaxDiagonal(dimensions);

    return 0;
}