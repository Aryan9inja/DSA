#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        // if(n-k-1 < 0){
        //     cout<<"No"<<"\n";
        //     continue;
        // }

        // int prev = -1;
        bool possible = true;

        for (int i = 0; i < k; i++) {
            int oneCnt = 0;

            for (int j = i; j < n; j += k) {
                if (s[j] == '1') {
                    oneCnt++;
                }
            }
            if (oneCnt & 1) {
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << "Yes" << "\n";
        }
        else {
            cout << "No" << "\n";
        }
    }

    return 0;
}