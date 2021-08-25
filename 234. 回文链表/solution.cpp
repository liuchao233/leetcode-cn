struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome1(ListNode* head) {
        int len = 0;

        ListNode *p = head;
        while (p != nullptr) {
            p = p->next;
            ++len;
        }

        if (len == 1) {
            return true;
        }
        
        int offset = (len - 1) / 2;
        ListNode* tail = head;
        for (int i = 0; i < offset; ++i) {
            tail = tail->next;
        }

        p = tail->next;
        while (p->next != nullptr) {
            ListNode* q = p->next;
            p->next = q->next;
            
            q->next = tail->next;
            tail->next = q;
        }

        ListNode* m = head, *n = tail->next;
        while (n != nullptr) {
            if (m->val != n->val) {
                return false;
            }
            m = m->next;
            n = n->next;
        }
        return true;
    }

    void reverse(ListNode* head, ListNode* prev) {
        ListNode* next = head, *curr = head;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }

    bool isPalindrome(ListNode* head) {
        ListNode* fast = head, *slow = head;

        // 使用快慢指针找链表的中点。
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow = slow->next;
        // 是偶数的时候将fast移动到最后一个元素。
        if (fast->next != nullptr) {
            fast = fast->next;
        }

        // 翻转链表后，fast 为头指针
        reverse(slow, nullptr);

        // 比较头尾指针的数值
        while (fast != nullptr) {
            if (fast->val != head->val) {
                return false;
            }

            fast = fast->next;
            head = head->next;
        }

        return true;
    }
};