#include <iostream>
#include <vector>
using namespace std;

int bsFunc(vector<int>& arr,int s,int e){
    if(s>e) return -1;

    int mid=s+(e-s)/2;

    if(arr[mid]>arr[mid+1]){
        return mid;
    }

    if(arr[mid]<arr[mid+1]){
        return bsFunc(arr,mid+1,e);
    }
}

int peakIndexInMountainArray(vector<int>& arr){
    bsFunc(arr,0,arr.size()-1);
}

int main() {
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(2);
    arr.push_back(10);
    arr.push_back(5);

    cout<<peakIndexInMountainArray(arr);

    return 0;
}