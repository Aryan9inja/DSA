#pragma GCC optimize("O3")
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<int, int> memo;
vector<int> good_numbers;

void init() {
    for (int i = 1; i <= 9; ++i) {
        for (int j = 0; j <= 9; ++j) {
            auto dfs = [&](auto self, long long curr, int mask) -> void {
                if (curr > 1000000000LL) return;
                if (curr > 0) good_numbers.push_back((int)curr);

                if (curr * 10 + i <= 1000000000LL) {
                    self(self, curr * 10 + i, mask | (1 << i));
                }
                if (i != j && curr * 10 + j <= 1000000000LL) {
                    self(self, curr * 10 + j, mask | (1 << j));
                }
            };
            dfs(dfs, 0, 0);
        }
    }

    sort(good_numbers.begin(), good_numbers.end());
    good_numbers.erase(unique(good_numbers.begin(), good_numbers.end()), good_numbers.end());

    sort(good_numbers.begin(), good_numbers.end(), [](int a, int b) {
        return to_string(a).length() < to_string(b).length();
    });
}

inline bool is_good(long long n) {
    int mask = 0;
    while (n > 0) {
        mask |= (1 << (n % 10));
        n /= 10;
        if (__builtin_popcount(mask) > 2) return false;
    }
    return true;
}

void solve() {
    int x;
    cin >> x;

    if (memo.count(x)) {
        cout << memo[x] << "\n";
        return;
    }

    for (int y : good_numbers) {
        if (is_good((long long)x * y)) {
            memo[x] = y;
            cout << y << "\n";
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}