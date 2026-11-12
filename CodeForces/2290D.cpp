#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    string s;
    s.reserve(n);
    cin >> s;

    int ops = 0;
    while (true) {
      char maxMismatch = 'a';
      for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
          maxMismatch = max(maxMismatch, max(s[i], s[n - i - 1]));
        }
      }

      if (maxMismatch == 'a') {
        break;
      }

      for (char &c : s) {
        if (c == maxMismatch) {
          c--;
        }
      }

      ops++;
    }

    cout << ops << "\n";
  }

  return 0;
}
