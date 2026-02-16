#include<bits/stdc++.h>
using namespace std;

class Solution {
    void heapify(vector<int> &arr,int n, int i){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;

        if(left<n && arr[left]>arr[largest]){
            largest=left;
        }
        if(right<n && arr[right]>arr[largest]){
            largest=right;
        }
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
    }
    
  public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // merge both arrays
        a.insert(a.end(),b.begin(),b.end());
        
        // build heap
        int size=n+m;
        for(int i=size/2-1;i>=0;i--){
            heapify(a,size,i);
        }
        return a;
    }
};