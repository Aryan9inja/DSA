#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        long long n, k;
        cin>>n>>k;

        long long ans = 0;
        long long currCost = 1;

        while(n>=currCost){
            long long bits = min(k, n/currCost);

            ans += bits;
            n-=bits*currCost;

            currCost*=2;
        }

        cout<<ans<<"\n";
    }
    
    return 0;
}