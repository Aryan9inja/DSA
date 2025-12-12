#include<iostream>
#include<math.h>
using namespace std;

const int M=1000000007;

int factorial(int n){
    int ans=1;
    while(n>=2){
        ans=(1LL*(ans%M)*(n%M))%M;
        n--;
    }
    return ans;
}

int main(){
    cout<<"Factorial of 212 is\n"<<factorial(212);
    return 0;
}