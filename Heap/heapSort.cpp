#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right <= n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Make max-heap
    for (int i = n / 2;i > 0;i--) {
        heapify(arr, n, i);
    }

    while(n>1){
        // swap largest element to last
        swap(arr[1],arr[n]);
        // remove last element from scope
        n--;

        // heapify to get first element to right position
        heapify(arr,n,1);
    }
}

int main() {
    int arr[6] = { -1,29,48,55,65,32 };
    int n = 5;

    cout << "Array before sorting:\n";
    for (int i = 1;i <= n;i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    heapSort(arr, n);

    cout << "Array after sorting:\n";
    for (int i = 1;i <= n;i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return EXIT_SUCCESS;
}