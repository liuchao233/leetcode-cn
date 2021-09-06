struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        // 1. 计算链表的总长度 l，找到头尾指针
        ListNode *tail = head;
        int len = 1;
        while (tail->next != nullptr) {
            ++len;
            tail = tail->next;
        }

        // 2. 计算需要挪动的实际距离，右移 m 位，相当与左移 l - m 位
        int realMove = len - k % len;
        // 如果右移的次数为 0，则不移动
        if (realMove == len) {
            return head;
        }

        while (realMove > 0) {
            ListNode *p = head;
            head = p->next;
            p->next = tail->next;
            tail->next = p;
            tail = p;
            --realMove;            
        }
        
        return head;
    }
};