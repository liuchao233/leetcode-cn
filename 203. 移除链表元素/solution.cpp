struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode fakeHead, *p = &fakeHead;
        fakeHead.next = head;
        
        while (p->next != nullptr) {
            ListNode *q = p->next;
            if (q->val == val) {
                p->next = q->next;
                q->next = nullptr;
            } else {
                p = p->next;                
            }
        }

        return fakeHead.next;
    }
};