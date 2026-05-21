#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int K_min = 0;
    int pref_max = -1;
    
    for (int i = 0; i < n; i++) {
        if (pref_max > a[i]) {
            K_min = max(K_min, pref_max - a[i]);
        }
        pref_max = max(pref_max, a[i]);
    }

    if (K_min == 0) {
        cout << "Yes\n";
        return;
    }

    vector<int> suff_min(n);
    suff_min[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suff_min[i] = min(suff_min[i + 1], a[i]);
    }

    vector<bool> L(n, false);
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > suff_min[i + 1]) {
            L[i] = true;
        }
    }

    bool has_1 = false;
    int max_1 = -1;
    pref_max = -1;
    
    for (int i = 0; i < n; i++) {
        bool in_R = (pref_max > a[i]); 
        
        bool propagated = (has_1 && a[i] < max_1 + K_min);

        if (in_R || propagated) {
            if (L[i]) {
                cout << "No\n";
                return;
            }
            if (!has_1) {
                has_1 = true;
                max_1 = a[i];
            } else {
                max_1 = max(max_1, a[i]);
            }
        }
        pref_max = max(pref_max, a[i]);
    }

    cout << "Yes\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}