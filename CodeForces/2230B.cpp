#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;

        int dp2 = 0;
        int dp13 = 0;

        for(char c : s){
            if(c == '2'){
                dp2 += 1;
            }else if(c == '1' || c == '3'){
                dp13 = max(dp13 + 1, dp2 + 1);
            }
        }

        int keep = max(dp2, dp13);
        int removals = static_cast<int>(s.size()) - keep;
        cout << removals << '\n';
    }
    
    return 0;
}