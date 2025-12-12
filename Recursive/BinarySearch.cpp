#include <iostream>
using namespace std;

bool binarySearch(int arr[], int s, int e, int key) {
    if (s > e) return false;

    int mid = s + (e - s) / 2;
    if (arr[mid] == key) return true;

    if (arr[mid] > key) {
        return binarySearch(arr, s, mid - 1, key);
    }
    else {
        return binarySearch(arr, mid + 1, e, key);
    }
}

int main() {
    int arr[] = { 1,2,3,4,5,6,7 };

    cout << binarySearch(arr, 0, 6, 7);

    return 0;
}