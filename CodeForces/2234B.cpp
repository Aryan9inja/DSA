#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const array<long long, 12> smallestPalindromeForRemainder = {
        0,1,2,3,4,5,6,7,8,9,22,11
    };

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        int remainderWhenDividedByTwelve = static_cast<int>(n % 12);

        long long a = smallestPalindromeForRemainder[remainderWhenDividedByTwelve];

        if (a > n) {
            cout << -1 << '\n';
            continue;
        }

        long long b = n - a;

        cout << a << ' ' << b << '\n';
    }

    return 0;
}