#include<iostream>
#include<map>
using namespace std;

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
        cout << "Node with value " << value << " deleted" << "\n";
    }
};

void insertAtTail(Node*& tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void printLinkedList(Node*& head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

bool isCircular(Node* head) {
    if (head == NULL) return true;

    Node* curr = head->next;

    while (curr != head && curr != NULL) {
        curr = curr->next;
    }

    return curr == head;
}

bool isCircularMap(Node* head) {
    if (head == NULL) return true;

    Node* curr = head;

    map<Node*, bool> check;

    while (curr != NULL && check[curr] != true) {
        curr=curr->next;
    }

    return curr==NULL?false:true;
}

int main() {
    Node* node1 = new Node(3);
    Node* tail = node1;
    Node* head = node1;

    insertAtTail(tail, 5);

    printLinkedList(head);

    cout << "Is Circular " << isCircular(head)<<"\n";
    cout<<"Is circular"<<isCircularMap(head);
    return 0;
}