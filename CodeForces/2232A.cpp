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

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }

        sort(a.begin(), a.end());

        int target = a[n/2];

        int lefts = 0;
        int rights = 0;

        for(int i=0; i<n; i++){
            if(a[i]<target) lefts++;
            else if(a[i]>target) rights++;
        }

        cout<<max(lefts, rights)<<"\n";
    }
    
    return 0;
}