struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        ListNode *tail = head;

        while (tail->next != nullptr) {
            ListNode *p = tail->next;
            tail->next = p->next; 
            p->next = head;
            head = p;
        }

        return head;
    }
};