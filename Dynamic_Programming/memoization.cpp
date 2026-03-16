#include<bits/stdc++.h>
using namespace std;

// O(n)
int fib(int n, vector<int>& dp) {
    if (n < 0) {
        return -1;
    }
    else if (n == 0 || n == 1) {
        return n;
    }

    if (dp[n] != -1) return dp[n];

    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

// O(2^n)
int fibT(int n) {
    if (n < 0) {
        return -1;
    }
    else if (n == 0 || n == 1) {
        return n;
    }

    return fibT(n - 1) + fibT(n - 2);
}

int main() {

    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);
    cout << fib(n, dp) << "\n";

    // cout<<fibT(n)<<"\n";

    return 0;
}