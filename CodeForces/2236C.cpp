#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long a, b, x;
        cin >> a;
        cin >> b;
        cin >> x;

        vector<pair<long long, int>> aStates;
        vector<pair<long long, int>> bStates;

        aStates.push_back({ a, 0 });
        int divRate = 0;
        while (a > 0) {
            a /= x;
            divRate++;
            aStates.push_back({ a, divRate });
        }

        bStates.push_back({ b, 0 });
        divRate = 0;
        while (b > 0) {
            b /= x;
            divRate++;
            bStates.push_back({ b, divRate });
        }

        long long mini = 2e9;

        for (const auto& stateA : aStates) {
            for (const auto& stateB : bStates) {
                long long a = stateA.first;
                long long aOps = stateA.second;

                long long b = stateB.first;
                long long bOps = stateB.second;

                long long ops = aOps + bOps + abs(a - b);
                mini = min(mini, ops);
            }
        }

        cout << mini << "\n";
    }

    return 0;
}