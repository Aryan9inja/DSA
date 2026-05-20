#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // O(n^2) - OK for problem constraints
    /*
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<bool> preA(n, false), preB(n, false);

        vector<int> ans(n);
        for(int i=0; i<n; i++){
            int eleA = A[i];
            int eleB = B[i];

            preA[eleA-1] = true;
            preB[eleB-1] = true;

            int curr = 0;
            for(int j = 0; j<n; j++){
                if(preA[j]!=false && preB[j]!=false){
                    curr++;
                }
            }

            ans[i] = curr;
        }

        return ans;
    }
    */

    // O(n) - Optimal
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> mp(A.size() + 1, 0);
        int count = 0;
        for (int i = 0;i < A.size();i++) {
            if (A[i] == B[i]) {
                mp[A[i]] += 2;
                count++;
            }
            else {
                mp[A[i]]++;
                mp[B[i]]++;
                if (mp[A[i]] == 2) { count++; }
                if (mp[B[i]] == 2) { count++; }
            }
            A[i] = count;
        }
        return A;
    }
};