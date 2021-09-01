struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        ListNode *p = headA, *q = headB;
        int lenA = 0, lenB = 0;
        while (p != nullptr) {
            p = p->next;
            ++lenA;
        }

        while (q != nullptr) {
            q = q->next;
            ++lenB;
        }

        p = headA;
        q = headB;

        if (lenA < lenB) {
            int offset = lenB - lenA;
            while (offset > 0) {
                q = q->next;
                --offset;
            }
        } else if (lenA > lenB) {
            int offset = lenA - lenB;
            while (offset > 0) {
                p = p->next;
                --offset;
            }
        }
        
        while (p != nullptr && q!= nullptr) {
            if (p == q) {
                return p;
            }
            p = p->next;
            q = q->next;
        }

        return nullptr;
    }
};