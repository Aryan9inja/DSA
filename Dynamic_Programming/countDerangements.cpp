#include<bits/stdc++.h>
using namespace std;

// (n-1)*[Solution of subproblems]
// subproblem 1 using swap with any i index 
// making them permanent indexes - f(n-2)
// subproblem 2 using swap with any i index
// not making the i index permanent - f(n-1)
// So, relation becomes - (n-1)*[f(n-2) + f(n-1)]

 /* Recurrence: (n-1) * [f(n-1) + f(n-2)]
       
    Pick an element '1' and put it in spot 'i' (n-1 choices).
    Now, what does element 'i' do?
       
    1. Two-way swap: 'i' takes spot '1'. 
      Both are settled. Derange the remaining (n-2) elements. -> f(n-2)
          
    2. Sequential shift: 'i' is forbidden from spot '1'. 
      This is like deranging (n-1) elements where 'i' has one 'forbidden' spot. -> f(n-1)
*/

#include<vector>
#define MOD 1000000007

long long int recursive(int n){
    // base case
    if(n==1) return 0;
    if(n==2) return 1;

    long long int ans=(n-1)*((recursive(n-1)%MOD)
    +(recursive(n-2)%MOD))%MOD;
    return ans;
}

long long int memoization(int n, vector<long long int> &dp){
    // base case
    if(n==1) return 0;
    if(n==2) return 1;

    if(dp[n]!=-1) return dp[n];

    dp[n]=(n-1)*((memoization(n-1,dp)%MOD)
    +(memoization(n-2,dp)%MOD))%MOD;
    return dp[n];
}

long long int tabulation(int n){
    vector<long long int> dp(n+1);

    dp[1]=0;
    dp[2]=1;

    for(int i=3;i<=n;i++){
        long long int first=dp[i-1] % MOD;
        long long int second=dp[i-2] % MOD;
        long long int sum = (first + second) % MOD;

        long long int ans = ((i-1)*sum)%MOD;
        dp[i]=ans;
    }
    return dp[n];
}

long long int spaceOptimization(int n){
    vector<long long int> dp(n+1);

    long long int prev2=0;
    long long int prev1=1;

    for(int i=3;i<=n;i++){
        long long int first=prev2 % MOD;
        long long int second=prev1 % MOD;
        long long int sum = (first + second) % MOD;

        long long int ans = ((i-1)*sum)%MOD;
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}

long long int countDerangements(int n) {
    // return recursive(n);
    // vector<long long int> dp(n+1, -1);
    // return memoization(n, dp);
    // return tabulation(n);
    return spaceOptimization(n);
}