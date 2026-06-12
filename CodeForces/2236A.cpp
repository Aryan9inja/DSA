#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;

        int maxi = 0;
        int mini = 1e5;

        int h;
        while(n--){
            cin >> h;

            maxi = max(maxi, h);
            mini = min(mini, h);
        }

        int ans = maxi - mini +1;
        cout<<ans<<"\n";
    }
    
    return 0;
}