#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        cout << "Node with value " << value << " deleted" << "\n";
    }
};

void insertAtHead(Node*& head, Node*& tail, int data) {
    Node* temp = new Node(data);
    if (head == NULL) {
        head = temp;
        tail = temp;
        return;
    }


    head->prev = temp;
    temp->next = head;
    head = temp;
}

void insertAtTail(Node*& tail, Node*& head, int data) {
    Node* temp = new Node(data);
    if (tail == NULL) {
        head = temp;
        tail = temp;
        return;
    }


    tail->next = temp;
    temp->prev = tail;
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

int getLength(Node*& head) {
    int len = 0;
    Node* temp = head;

    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtPosition(Node*& head, Node*& tail, int data, int position) {
    if (position == 1) {
        insertAtHead(head, tail, data);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < position - 1) {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL) {
        insertAtTail(tail, head, data);
        return;
    }

    Node* NodeToInsert = new Node(data);
    NodeToInsert->next = temp->next;
    temp->next->prev = NodeToInsert;
    temp->next = NodeToInsert;
    NodeToInsert->prev = temp;
}

void deleteNode(int position, Node*& head, Node*& tail) {
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < position && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL) {
        tail = temp->prev;
        temp->prev->next = NULL;
        delete temp;
        return;
    }

    temp->prev->next = temp->next;
    delete temp;
}

Node* reverseDoubly(Node* &head){
    Node* forward=head->next;
    
    while(forward!=NULL && forward->next!=NULL){
        head->next=head->prev;
        head->prev=forward;
        head=forward;
    }
    return head;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    printLinkedList(head);
    cout << "Current length of linked list is: " << getLength(head) << "\n\n";
    insertAtHead(head, tail, 12);
    printLinkedList(head);
    cout << "Current head: " << head->data << "\n";
    cout << "Current tail: " << tail->data << "\n";
    cout << "Current length of linked list is: " << getLength(head) << "\n\n";
    insertAtTail(tail, head, 77);
    printLinkedList(head);
    cout << "Current head: " << head->data << "\n";
    cout << "Current tail: " << tail->data << "\n";
    cout << "Current length of linked list is: " << getLength(head) << "\n\n";
    insertAtPosition(head, tail, 20, 3);
    printLinkedList(head);
    cout << "Current head: " << head->data << "\n";
    cout << "Current tail: " << tail->data << "\n";
    cout << "Current length of linked list is: " << getLength(head) << "\n\n";
    deleteNode(3, head, tail);
    printLinkedList(head);
    cout << "Current head: " << head->data << "\n";
    cout << "Current tail: " << tail->data << "\n";
    cout << "Current length of linked list is: " << getLength(head) << "\n\n";
    Node* reversedHead=reverseDoubly(head);
    printLinkedList(reversedHead);
    cout << "Current head: " << head->data << "\n";
    cout << "Current tail: " << tail->data << "\n";
    cout << "Current length of linked list is: " << getLength(head) << "\n\n";

    return 0;
}