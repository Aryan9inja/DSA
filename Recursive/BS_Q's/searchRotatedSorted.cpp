#include<iostream>
using namespace std;

int findPivot(int arr[], int s, int e) {
    if (s == e) return s;

    int mid = s + (e - s) / 2;

    if (arr[mid] >= arr[0]) return findPivot(arr, mid + 1, e);

    return findPivot(arr, s, mid);
}

int binarySearch(int arr[], int s, int e, int key) {
    if (s > e) return -1;

    int mid = s + (e - s) / 2;
    if (arr[mid] == key) return mid;

    if (arr[mid] > key) {
        return binarySearch(arr, s, mid - 1, key);
    }
    else {
        return binarySearch(arr, mid + 1, e, key);
    }
}

int searchRotatedSorted(int arr[], int n, int k) {
    int pivot = findPivot(arr, 0, n - 1);

    if (k >= arr[pivot] && k <= arr[n - 1])
        return binarySearch(arr, pivot, n - 1, k);
    return binarySearch(arr, 0, pivot, k);
}

int main() {
    int arr[] = { 5,7,9,1,2,3,4 };

    cout<<searchRotatedSorted(arr,7,8);

    return 0;
}