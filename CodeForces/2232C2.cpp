#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        long long s;
        cin >> n >> x >> s;

        string u;
        cin >> u;

        int empty_tables = x;
        long long partial_seats = 0;
        int seated = 0;

        int a_as_e = 0;

        for (char c : u) {
            if (c == 'I') {
                if (empty_tables > 0) {
                    empty_tables--;
                    partial_seats += (s - 1);
                    seated++;
                }
            }
            else if (c == 'E') {
                if (partial_seats > 0) {
                    partial_seats--;
                    seated++;
                }
                else if (empty_tables > 0 && a_as_e > 0) {
                    a_as_e--;
                    empty_tables--;

                    partial_seats += (s - 1);
                    seated++;
                }
            }
            else if (c == 'A') {
                if (partial_seats > 0) {
                    partial_seats--;
                    seated++;
                    a_as_e++;
                }
                else if (empty_tables > 0) {
                    empty_tables--;
                    partial_seats += (s - 1);
                    seated++;
                }
            }
        }

        cout << seated << "\n";
    }

    return 0;
}