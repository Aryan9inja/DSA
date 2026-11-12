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

    map<int, int> mp;
    int maxi = 0;
    for (int i = 0; i < n; i++) {
      int h;
      cin >> h;
      maxi = max(maxi, h);
      mp[h]++;
    }

    vector<int> l, m, r;
    for (auto &[h, x] : mp) {
      l.push_back(h);
      if (x > 1) {
        r.push_back(h);
      }
      for (int i = 2; i < x; i++) {
        m.push_back(h);
      }
    }

    reverse(r.begin(), r.end());
    int ans = l.size() + r.size();
    cout << ans << "\n";

    vector<int> res;
    res.reserve(n);
    for (int &h : l)
      res.push_back(h);
    for (int &h : m)
      res.push_back(h);
    for (int &h : r)
      res.push_back(h);

    for (int i = 0; i < n; i++) {
      cout << res[i] << (i + 1 == n ? "" : " ");
    }
    cout << "\n";
  }

  return 0;
}
