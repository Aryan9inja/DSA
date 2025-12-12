#include <iostream>

class Stack {
public:
    int* arr;
    int top;
    int size;

    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data) {
        if (size - top > 1) {
            top++;
            arr[top] = data;
        }
        else {
            std::cout << "Stack Overflow\n";
        }
    }

    void pop() {
        if (top >= 0) {
            top--;
        }
        else {
            std::cout << "Stack Underflow\n";
        }
    }

    int peek() {
        if (top >= 0) {
            return arr[top];
        }
        else {
            return -1;
        }
    }

    bool isEmpty() {
        if (top == -1) return true;
        else return false;
    }
};

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        std::cout << "Node with value " << value << " deleted" << "\n";
    }
};

class StackLL {
public:
    int size;
    Node* top;
    int currentCapacity;

    StackLL(int size) {
        this->size = size;
        top = NULL;
        currentCapacity = 0;
    }

    bool isEmpty() {
        return top == NULL;
    }

    bool isFull() {
        return size == currentCapacity;
    }

    void push(int data) {
        if (isFull()) {
            std::cout << "Stack Overflow! Cannot push " << data << "\n";
            return;
        }
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        currentCapacity++;
        std::cout << data << " pushed onto stack\n";
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow! Cannot pop\n";
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        currentCapacity--;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }

};

int main() {
    StackLL s(5);
    s.push(22);
    s.push(43);
    s.push(42);
    int top = s.peek();
    std::cout << "Top is " << top << "\n";
    s.pop();
    top = s.peek();
    std::cout << "Top is " << top << "\n";
}