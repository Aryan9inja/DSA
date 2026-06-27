#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long d;
        cin >> n >> d;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<long long> x(3 * n);
        for (int i = 0; i < 3 * n; i++) {
            x[i] = a[i % n];
        }

        vector<long long> prefix(3 * n + 1, 0);
        for (int i = 0; i < 3 * n; i++) {
            prefix[i + 1] = prefix[i] + x[i];
        }

        long long ans = 0;

        for(int i=0; i<n; i++){
            int middle = i+n;

            long long winSum = prefix[middle+d+1] - prefix[middle-d];
            long long fieldOfView = winSum - a[i];

            long long contri = 2*d*a[i] - fieldOfView;

            if(contri > 0){
                ans+=contri;
            }
        }

        cout<<ans<<"\n";
    }

    return 0;
}