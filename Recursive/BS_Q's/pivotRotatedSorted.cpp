#include<iostream>
using namespace std;

int binaryFunc(int arr[],int s,int e){
    if(s==e) return s;

    int mid=s+(e-s)/2;

    if(arr[mid]>=arr[0]) return binaryFunc(arr,mid+1,e);

    return binaryFunc(arr,s,mid);
}

int findPivot(int arr[],int n){
    return binaryFunc(arr,0,n-1);
}

int main() {
    int arr[] = { 5,7,9,1,2,3,4 };

    cout<<findPivot(arr,7);

    return 0;
}