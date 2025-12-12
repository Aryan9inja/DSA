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

void insertNode(Node*& tail, int data) {
    Node* temp = new Node(data);
    if (tail == NULL) {
        temp->next = temp;
        tail = temp;
        return;
    }

    temp->next = tail->next;
    tail->next = temp;
    tail = temp;
}

void insertNodeByValue(Node*& tail, int prevNode, int data) {
    Node* temp = new Node(data);
    if (tail == NULL) {
        temp->next = temp;
        tail = temp;
        return;
    }

    Node* itr = tail;
    while (itr->data != prevNode) {
        itr = itr->next;
    }
    temp->next = itr->next;
    itr->next = temp;
    
    if(itr==tail){
        tail=temp;
    }
}

void deleteNode(Node*& tail, int val) {
    if (tail == NULL) {
        cout << "List is already empty" << "\n";
        return;
    }

    Node* curr = tail;
    Node* prev = NULL;

    do {
        if (curr->data == val) {
            break;
        }
        prev=curr;
        curr=curr->next;
    } while (curr != tail);

    if (curr->data != val) {
        cout << "Invalid value to delete" << "\n";
        return;
    }

    if(curr->next==curr){
        tail=NULL;
        delete curr;
        return;
    }

    if(curr == tail){
        tail=prev;
    }

    prev->next=curr->next;
    delete curr;
}

void printLinkedList(Node*& tail) {
    if (tail == NULL) {
        cout << "List is empty" << "\n";
        return;
    }

    Node* temp = tail->next;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << "\n";
}

bool isCircular(Node* head){
    if(head==NULL) return true;

    Node* curr=head->next;

    while(curr!=head && curr!=NULL){
        curr=curr->next;
    }

    return curr==head;
}

// Can also be used to detect loop
bool isCircularMap(Node* head) {
    if (head == NULL) return true;

    Node* curr = head;

    map<Node*, bool> check;

    while (curr != NULL && check[curr] != true) {
        curr=curr->next;
    }

    return curr==NULL?false:true;
}

Node* cycleDetectFloyd(Node* head){
    if(head==NULL) return NULL;

    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(fast==slow){
            return slow;
        }
    }

    return NULL;
}

Node* getCycleStartFloyd(Node* head){
    if(head==NULL) return NULL;

    Node* intersectionNode=cycleDetectFloyd(head);

    Node* slow=head;

    while (slow!=intersectionNode)
    {
        slow=slow->next;
        intersectionNode=intersectionNode->next;
    }

    return slow;
}

void removeCycle(Node* head){
    if(head==NULL) return;

    Node* startOfCycle=getCycleStartFloyd(head);

    Node* temp=startOfCycle;

    while(temp->next!=startOfCycle){
        temp=temp->next;
    }

    temp->next=NULL;
}

int main() {
    Node* tail = NULL;
    printLinkedList(tail);
    insertNode(tail, 20);
    printLinkedList(tail);
    insertNode(tail, 32);
    printLinkedList(tail);
    insertNode(tail, 45);
    printLinkedList(tail);

    insertNodeByValue(tail, 32, 47);
    printLinkedList(tail);

    deleteNode(tail, 32);
    printLinkedList(tail);

    cout<<isCircular(tail)<<"\n";
    cout<<cycleDetectFloyd(tail)->data<<"\n";
    cout<<getCycleStartFloyd(tail)->data;

    return 0;
}