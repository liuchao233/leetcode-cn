struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p = l1, *q = l2, *prev = nullptr;
        int addon = 0;

        while (p != nullptr && q != nullptr) {
            int val = p->val + q->val + addon;
            p->val = val % 10;
            addon = val / 10;

            prev = p;
            p = p->next;
            q = q->next;
        }

        if (q != nullptr) {
            prev->next = q;
        }
        
        p = prev->next;
        while (p != nullptr && addon > 0) {
            int val = p->val + addon;
            p->val = val % 10;
            addon = val / 10;

            prev = p;
            p = p->next;
        }

        if (p == nullptr && addon > 0) {
            prev->next = new ListNode(addon);
        }

        return l1;      
    }
};