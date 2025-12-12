#include<iostream>
using namespace std;

int binaryFunc(int s,int e,int n){
    if(s==e) return s;

    int mid=s+(e-s)/2;

    if(mid*mid>n) return binaryFunc(s,mid-1,n);
    return binaryFunc(mid+1,e,n);
}

int sqrt(int n){
    return binaryFunc(0,n,n);
}

int main() {
    int n;
    cout<<"Enter a number to find square root\n";
    cin>>n;

    cout<<sqrt(n);

    return 0;
}