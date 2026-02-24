#include<bits/stdc++.h>
using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int,int> cnt;
    int maxFreq=0;
    int maxAns=0;

    for(int i : arr){
        cnt[i]++;
        maxFreq=max(maxFreq,cnt[i]);
    }

    for(int i : arr){
        if(maxFreq==cnt[i]){
            maxAns=i;
            break;
        }
    }
    return maxAns;
}