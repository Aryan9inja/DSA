#include <iostream>

class kQueues {
    int n, k;
    int* front;
    int* rear;
    int* next;
    int* arr;
    int freeSpot;

public:
    kQueues(int n, int k) {
        this->n = n;
        this->k = k;
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];
        freeSpot = 0;

        for (int i = 0;i < k;i++) {
            front[i] = -1;
            rear[i] = -1;
        }

        for (int i = 0;i < n;i++) next[i] = i + 1;
        next[n - 1] = -1;
    }

    void enqueue(int data, int qn) {
        // check overflow
        if (freeSpot == -1) {
            std::cout << "No empty space available";
            return;
        }

        // find free index
        int index = freeSpot;

        // update freeSpot
        freeSpot = next[index];

        // check if the element we are pushing is first
        if (front[qn - 1] == -1) front[qn - 1] = index;
        // link new element to previous element
        else next[rear[qn - 1]] = index;

        // update next
        next[index] = -1;

        // update rear
        rear[qn - 1] = index;

        // push element
        arr[index] = data;
    }

    int dequeue(int qn){
        // check underflow
        if(front[qn-1]==-1){
            std::cout<<"Queue underflow";
            return -1;
        }

        // find index to pop
        int index=front[qn-1];

        // front ko aage bdhao
        front[qn-1]=next[index];

        // free slot ko manage kro
        next[index]=freeSpot;

        // update free
        freeSpot=index;

        return arr[index];
    }
};