#include <iostream>
#include <vector>
using namespace std;

void recursiveInsertionSort(vector<int> &arr, int n) {
    // Base case: if size is 1, it's already sorted
    if (n <= 1) return;

    // Sort the first n-1 elements recursively
    recursiveInsertionSort(arr, n - 1);

    // Insert the last element at its correct position
    int last = arr[n - 1];
    int j = n - 2;

    // Shift elements to the right to insert "last"
    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

int main() {
    vector<int> arr = {5, 3, 4, 1, 2};
    int n = arr.size();

    recursiveInsertionSort(arr, n);

    for (int x : arr) cout << x << " ";
    return 0;
}
