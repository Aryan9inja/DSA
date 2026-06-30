#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        int answer;

        cin >> n;
        cin >> s;

        if (count(s.begin(), s.end(), '0') == n || count(s.begin(), s.end(), '1') == n) {
            answer = 1;
        }
        else if (is_sorted(s.begin(), s.end()) || is_sorted(s.rbegin(), s.rend())) {
            answer = 2;
        }
        else answer = 1;

        cout << answer << "\n";
    }

    return 0;
}