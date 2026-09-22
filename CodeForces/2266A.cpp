#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int mini = n;
        for (int i = 0; i < 3; i++) {
            int temp;
            cin >> temp;

            mini = min(mini, temp);
        }

        cout << (n - mini) << "\n";
    }

    return 0;
}