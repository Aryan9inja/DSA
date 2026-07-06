#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;

        int twiceCnt = 0;
        bool big = false;

        while (k--) {
            int temp;
            cin >> temp;

            if (temp == 2) {
                twiceCnt++;
            }
            if (temp >= 3) {
                big = true;
            }
        }

        if (twiceCnt >= 2 || big) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }

    return 0;
}