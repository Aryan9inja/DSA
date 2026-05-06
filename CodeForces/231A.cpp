#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0;i < n; i++) {
        int one = 0;
        for (int j = 0; j < 3; j++) {
            int temp;
            cin >> temp;
            if (temp == 1) one++;
        }
        if (one >= 2) ans++;
    }
    cout << ans;
    return 0;
}