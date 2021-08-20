#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
  
  
class Solution {
public:
    ListNode* reverseList1(ListNode* head) {
        // 如果链表为空，或者只有一个节点，直接返回不需要倒置
        if (head == NULL || head->next == NULL) return head;

        ListNode h = ListNode(-1);
        h.next = head;

        ListNode *p = head->next;

        while (p != NULL) {
            ListNode *q = p->next;
            p->next = h.next;
            h.next = p;
            p = q;
        }
        
        head->next = NULL;
        return h.next;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL, *cur = head;

        while (cur != NULL) {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp
        }

        return pre;
    }
};