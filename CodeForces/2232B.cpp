#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        long long sum = 0;
        long long min_h = 2000000000LL;
        
        for(int i = 1; i <= n; i++) {
            long long num;
            cin >> num;
            
            sum += num;
            
            long long current_max_h = sum / i; 
            
            min_h = min(min_h, current_max_h);
            
            cout << min_h << (i == n ? "" : " ");
        }
        cout << "\n";
    }
    
    return 0;
}