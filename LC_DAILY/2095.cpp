
struct ListNode {
int val;
ListNode *next;
ListNode() : val(0), next(nullptr) {}
ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
    int getLen(ListNode* head){
        int len = 0;
        ListNode* curr = head;
        while(curr != nullptr){
            len++;
            curr = curr->next;
        }
        return len;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        int n = getLen(head);

        if(n==1) return nullptr;
        int mid = n/2;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(mid--){
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        curr->next = nullptr;
        delete(curr);

        return head;
    }
};