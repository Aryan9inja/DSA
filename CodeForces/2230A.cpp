#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        long long n, a, b;
        cin >> n >> a >> b;

        long long groups = n / 3;
        long long rem = n % 3;

        long long groupCost = min(b, 3 * a);
        long long remCost = min(rem * a, b);

        long long ans = groups * groupCost + remCost;
        cout << ans << "\n";
    }
    
    return 0;
}