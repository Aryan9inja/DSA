#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // Approach one - data not preserved
        /*
        int zeroCnt = 0;
        for(int i : arr){
            if(i == 0) zeroCnt++;
        }
        
        for(int i=0; i<arr.size(); i++){
            if(zeroCnt){
                arr[i]=0;
                zeroCnt--;
            }
            else{
                arr[i]=1;
            }
        }
        */
        
        // Approach two - data is also preserved
        int n = arr.size();
        int low = -1;
        int high = n;
        
        while(1){
            do{
                low++;
            }while(low<n && arr[low]==0);
            
            do{
                high--;
            }while(high>=0 && arr[high]==1);
            
            if(low>=high) break;
            
            swap(arr[low], arr[high]);
        }
    }
};