#include <iostream>
using namespace std;

int main() {
    int W;
    cin >> W;

    if (W < 4 || W & 1) cout << "NO";
    else cout << "YES";

    return 0;
}