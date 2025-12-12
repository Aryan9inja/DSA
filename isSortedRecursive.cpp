#include <iostream>
using namespace std;

bool isSorted(int arr[], int size) {
    if (size == 1 || size == 0) return true;

    if(arr[0]>arr[1]){
        return false;
    }else{
        bool ans=isSorted(arr+1,size-1);
        return ans;
    }
}

int main() {
    int arr1[] = { 1,2,3,4,5 };
    int arr2[] = { 1,2,3,5,4 };

    cout << isSorted(arr2, 5);

    return 0;
}