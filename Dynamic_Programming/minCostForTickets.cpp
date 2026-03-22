#include<bits/stdc++.h>
using namespace std;

// Min cost for tickets
int recursive(int n, vector<int> &days, vector<int> &cost, int index){
    if(index>=n){
        return 0;
    }

    // 1 day pass
    int option1=cost[0]+recursive(n, days, cost, index+1);
    // 7 days pass
    int i;
    for(i=index; i<n && days[i]<days[index]+7; i++);
    int option2=cost[1]+recursive(n, days, cost, i);

    // 30 days pass
    for(i=index; i<n && days[i]<days[index]+30; i++);
    int option3=cost[2]+recursive(n, days, cost, i);\

    return min(option1, min(option2, option3));
}

int memoization(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp){
    if(index>=n){
        return 0;
    }

    if(dp[index]!=-1) return dp[index];

    // 1 day pass
    int option1=cost[0]+memoization(n, days, cost, index+1, dp);
    // 7 days pass
    int i;
    for(i=index; i<n && days[i]<days[index]+7; i++);
    int option2=cost[1]+memoization(n, days, cost, i, dp);

    // 30 days pass
    for(i=index; i<n && days[i]<days[index]+30; i++);
    int option3=cost[2]+memoization(n, days, cost, i, dp);

    dp[index]=min(option1, min(option2, option3));
    return dp[index];
}

int tabulation(int n, vector<int> &days, vector<int> &cost){
    vector<int> dp(n+1, INT_MAX);
    
    dp[n]=0;

    for(int k=n-1;k>=0;k--){
        int option1=cost[0]+dp[k+1];
        // 7 days pass
        int i;
        for(i=k; i<n && days[i]<days[k]+7; i++);
        int option2=cost[1]+dp[i];

        // 30 days pass
        for(i=k; i<n && days[i]<days[k]+30; i++);
        int option3=cost[2]+dp[i];

        dp[k]=min(option1, min(option2, option3));
    }
    return dp[0];
}

int minimumCoins(int n, vector<int> &days, vector<int> &cost)
{
    // return recursive(n, days, cost, 0);
    // vector<int> dp(n+1, -1);
    // return memoization(n, days, cost, 0, dp);
    // return tabulation(n, days, cost);

    // Optimized solution after this
    int ans=0;

    // day, cost
    queue<pair<int, int>> month;
    queue<pair<int, int>> week;

    for(int day:days){
        // step 1 : remove expired days
        while(!month.empty() && month.front().first+30 <= day){
            month.pop();
        }

        while(!week.empty() && week.front().first+7 <= day){
            week.pop();
        }

        // step 2 : add cost for current day
        month.push({day, ans+cost[2]});
        week.push({day, ans+cost[1]});

        // step 3 : update ans
        ans=min(ans+cost[0], min(week.front().second, month.front().second));
    }
    return ans;
}