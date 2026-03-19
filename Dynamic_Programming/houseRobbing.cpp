#include <bits/stdc++.h> 
using namespace std;

long long int solve(vector<int> &nums, int n, int start){
    long long int prev2=0;
    long long int prev1=nums[start];

    for(int i=start+1;i<=n;i++){
        long long int incl = prev2+nums[i];
        long long int excl= prev1+0;

        long long int ans=max(incl,excl);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    int n=valueInHouse.size();

    if(n==1) return valueInHouse[0];

    // max of 
    // including first but excluding last
    // excluding first but including last
    long long int ans=max(solve(valueInHouse, n-2, 0), solve(valueInHouse, n-1, 1));
    return ans;
}