#include<bits/stdc++.h>
using namespace std;

class MaxHeap {
public:
    int arr[100];
    int size;

    MaxHeap() {
        this->arr[0] = -1;
        this->size = 0;
    }

    void print() {
        for (int i = 1;i <= size;i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    void insertIntoHeap(int val) {
        int index = ++size;
        arr[index] = val;

        while (index > 1) {
            int parent = index / 2;

            if (arr[parent] < arr[index]) {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else {
                return;
            }
        }
    }

    // We delete root element
    void deleteFromHeap() {
        if (size == 0) {
            cout << "Nothing to delete LOL\n";
            return;
        }

        // remove last element (size--) and replace it to top
        int i = 1;
        arr[i] = arr[size--];

        while (i <= size) {
            int leftIndex = i * 2;
            int rightIndex = i * 2 + 1;
            int largest = i;

            if (leftIndex <= size && arr[leftIndex] > arr[largest]) {
                largest = leftIndex;
            }
            if (rightIndex <= size && arr[rightIndex] > arr[largest]) {
                largest = rightIndex;
            }

            if (largest != i) {
                swap(arr[largest], arr[i]);
                i = largest;
            }
            else {
                return;
            }
        }
    }

    void heapify(int arr[],int n, int i){
        int largest=i;
        int left=2*i;
        int right=2*i+1;

        if(left<=n && arr[left]>arr[largest]){
            largest=left;
        }
        if(right<=n && arr[right]>arr[largest]){
            largest=right;
        }
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
    }
};

int main() {
    MaxHeap heap;
    heap.insertIntoHeap(50);
    heap.insertIntoHeap(55);
    heap.insertIntoHeap(56);
    heap.insertIntoHeap(48);
    heap.insertIntoHeap(65);
    heap.print();
    heap.deleteFromHeap();
    heap.print();
    heap.deleteFromHeap();
    heap.print();

    int arr[6]={-1,50,55,56,48,65};
    int n=5;
    for(int i=n/2;i>0;i--){
        heap.heapify(arr,n,i);
    }
    for(int i=1;i<6;i++){
        cout<<arr[i]<<" ";
    }
    return EXIT_SUCCESS;
}