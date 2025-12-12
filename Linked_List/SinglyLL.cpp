#include<iostream>
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
        cout<<"Node with value "<<value<<" deleted"<<"\n";
    }
};

void insertAtHead(Node*& head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node*& tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node*& head, Node*& tail, int position, int d) {
    if (position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < position - 1) {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL) {
        insertAtTail(tail, d);
        return;
    }

    Node* newNode = new Node(d);

    newNode->next = temp->next;

    temp->next = newNode;
}

void deleteAtPosition(Node*& head, int position) {
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* prev = NULL;
    Node* curr = head;
    int cnt = 1;

    while (cnt < position && curr != NULL) {
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    if (curr == NULL) {
        return;
    }

    prev->next = curr->next;

    delete curr;
}

void printLinkedList(Node*& head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    Node* node1 = new Node(10);

    // cout<<node1->data<<"\n";
    // cout<<node1->next<<"\n";
    Node* head = node1;
    printLinkedList(head);
    insertAtHead(head, 12);
    printLinkedList(head);
    insertAtHead(head, 15);
    printLinkedList(head);

    Node* tail = node1;
    insertAtTail(tail, 12);
    printLinkedList(head);
    insertAtTail(tail, 15);
    printLinkedList(head);

    insertAtPosition(head, tail, 3, 77);
    printLinkedList(head);

    deleteAtPosition(head, 1);
    printLinkedList(head);
    deleteAtPosition(head, 3);
    printLinkedList(head);
    return 0;
}