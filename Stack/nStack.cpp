#include <bits/stdc++.h> 
class NStack
{
    int *arr;
    int *top;
    int *next;

    int freespot;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        arr=new int[S];
        top=new int[N];
        next=new int[S];

        // Initialize Top
        for(int i = 0; i < N; i++) {
            top[i] = -1;
        }

        //Initialize next
        for(int i=0;i<S;i++) next[i]=i+1;
        next[S-1]=-1;

        freespot=0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        //Check Overflow
        if(freespot==-1) return false;

        //Get index
        int index=freespot;

        //Add element to array
        arr[index]=x;

        //Update freespot
        freespot=next[index];

        //Update Next
        next[index]=top[m-1];

        //Update Top
        top[m-1]=index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        //Check Underflow
        if(top[m-1]==-1){
            return -1;
        }

        //Get array index
        int index=top[m-1];

        //Update top
        top[m-1]=next[index];

        //Update next
        next[index]=freespot;

        //Update freespot
        freespot=index;

        return arr[index];
    }
};