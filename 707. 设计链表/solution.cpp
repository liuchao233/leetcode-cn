struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MyLinkedList {
public:
    ListNode* head = nullptr;

    /** Initialize your data structure here. */
    MyLinkedList() {
        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        ListNode *p = head;
        while (index > 0) {
            if (p == nullptr) {
                return -1;
            }
            p = p->next;
            --index;
        }

        if (p == nullptr) {
            return -1;
        }
        return p->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode *node = new ListNode(val);
        node->next = head;
        head = node;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *node = new ListNode(val);
        if (head == nullptr) {
            head = node;
        } else {
            ListNode *p = head;
            while (p->next != nullptr) {
                p = p->next;
            }
            p->next = node;
        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index <= 0) {
            addAtHead(val);
        } else {
            ListNode *p = head;

            while (index > 1) {
                if (p == nullptr) {
                    return;
                }
                --index;
                p = p->next;
            }

            ListNode *node = new ListNode(val);
            node->next = p->next;
            p->next = node;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || head == nullptr) {
            return;
        }

        if (index == 0) {
            ListNode *p = head;
            head = head->next;
            delete p;
        } else {
            ListNode *p = head;
            while (index > 1) {
                if (p == nullptr) {
                    return;
                }
                --index;
                p = p->next;
            }

            if (p == nullptr) {
                return;
            }

            ListNode *q = p->next;
            if (q != nullptr) {
                p->next = q->next;
                delete q;
            }
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */