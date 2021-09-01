struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *p = head, *q = head;

        while (q != nullptr) {
            p = p->next;
            if (q->next == nullptr) {
                return nullptr;
            }
            q = q->next->next;

            if (p == q) {
                p = head;
                while (p != q) {
                    p = p->next;
                    q = q->next;
                }
                return p;
            }
        }

        return nullptr;
    }
};