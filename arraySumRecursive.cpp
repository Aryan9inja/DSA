#include <iostream>
using namespace std;

int sum(int arr[],int size){
    if(size==0){
        return 0;
    }

   int ans=arr[0]+sum(arr+1,size-1);
   return ans;
}

int main() {
    int arr1[] = { 1,2,3,4,5,7 };
    int arr2[] = { 1,2,3,5,4 };

    cout << sum(arr1, 6);

    return 0;
}