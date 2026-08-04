#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        vector<int> v = { a, b, c };
        sort(v.begin(), v.end());

        cout << min(v[1] - v[0], v[2] - v[1]) << '\n';
    }

    return 0;
}