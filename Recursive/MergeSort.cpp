#include<iostream>
using namespace std;

// Function to merge two sorted halves of an array
void merge(int arr[], int s, int e) {
    // Find the middle point
    int mid = s + (e - s) / 2;

    // Lengths of the two halves
    int len1 = mid - s + 1;
    int len2 = e - mid;

    // Create temporary arrays for both halves
    int* first = new int[len1];
    int* second = new int[len2];

    // Copy elements into the first half
    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    // Copy elements into the second half
    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    // Indices for traversing temporary arrays
    int index1 = 0, index2 = 0;
    mainArrayIndex = s;

    // Merge both halves into the main array in sorted order
    while (index1 < len1 && index2 < len2) {
        if (first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        } else {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    // Copy any remaining elements from first half
    while (index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    // Copy any remaining elements from second half
    while (index2 < len2) {
        arr[mainArrayIndex++] = second[index2++];
    }

    // Free the dynamically allocated memory
    delete[] first;
    delete[] second;
}

// Recursive Merge Sort function
void mergeSort(int arr[], int s, int e) {
    // Base case: if array has 1 or 0 elements, it's already sorted
    if (s >= e) return;

    // Find the mid index
    int mid = s + (e - s) / 2;

    // Recursively sort the left half
    mergeSort(arr, s, mid);

    // Recursively sort the right half
    mergeSort(arr, mid + 1, e);

    // Merge the sorted halves
    merge(arr, s, e);
}

int main() {
    // Example array
    int arr[] = { 7, 9, 5, 3, 6, 2, 1, 2 };

    // Call merge sort on full array (indices 0 to 7)
    mergeSort(arr, 0, 7);

    // Print the sorted array
    for (int element : arr) {
        cout << element << " ";
    }
    return 0;
}
