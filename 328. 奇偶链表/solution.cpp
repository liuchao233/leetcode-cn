struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *oddHead = head, *evenHead = head->next, *p = head->next->next;
        ListNode *odd = head, *even = evenHead;
        bool isOdd = true;

        while (p != nullptr) {
            if (isOdd) {
                even->next = p->next;
                p->next = evenHead;
                odd->next = p;
                odd = p;
                p = even->next;
            } else {
                even = p;
                p = p->next;
            }
            isOdd = !isOdd;
        }

        return head;
    }
};