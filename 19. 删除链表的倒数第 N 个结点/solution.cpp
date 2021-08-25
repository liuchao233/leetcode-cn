struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode newHead = ListNode();
        newHead.next = head;
        
        ListNode*p = &newHead, *q = head;

        for (int i = 0; i < n; ++i) {
            q = q->next;
        }     

        while (q != nullptr) {
            p = p->next;
            q = q->next;
        }   

        ListNode *temp = p->next;
        p->next = temp->next;
        temp->next = nullptr;

        return newHead.next;        
    }
};