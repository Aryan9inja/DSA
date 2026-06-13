#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    int getLen(ListNode* head) {
        int len = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            len++;
            curr = curr->next;
        }
        return len;
    }

    int pairSum(ListNode* head) {
        int n = getLen(head);

        int partSize = n / 2;
        ListNode* curr = head;
        // Move to the start of the second half
        while (partSize--) {
            curr = curr->next;
        }

        ListNode* p1 = head;
        ListNode* p2 = reverseList(curr);

        int ans = 0;
        while (p2 != nullptr) {
            int sum = p1->val + p2->val;
            ans = max(ans, sum);

            p1 = p1->next;
            p2 = p2->next;
        }

        return ans;
    }
};