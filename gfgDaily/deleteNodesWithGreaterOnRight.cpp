#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
private:
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr != nullptr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

public:
    Node* compute(Node* head) {
        if (!head || !head->next) return head;

        // Step 1: Reverse the list so we can traverse from right to left
        head = reverseList(head);

        Node* curr = head;
        Node* maxNode = head;

        // Step 2: Traverse and delete nodes smaller than maxNode
        while (curr != nullptr && curr->next != nullptr) {
            if (curr->next->data < maxNode->data) {
                Node* temp = curr->next;
                curr->next = temp->next;
                delete temp;
            }
            else {
                curr = curr->next;
                maxNode = curr;
            }
        }

        // Step 3: Reverse back to restore original order
        return reverseList(head);
    }
};