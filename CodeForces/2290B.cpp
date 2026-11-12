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

    char curr = 'R';
    int ans = 0;
    for (char &c : s) {
      if (curr == 'R' && c == 'B') {
        ans++;
        curr = 'B';
      } else if (curr == 'B' && c == 'R') {
        ans++;
        curr = 'R';
      }

      if (curr == 'R') {
        curr = 'B';
      } else {
        curr = 'R';
      }
    }

    cout << ans << "\n";
  }

  return 0;
}
