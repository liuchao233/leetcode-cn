class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    // return tail
    Node* _flatten(Node* head, Node* tail) {
        if (head == nullptr) {
            return head;
        }

        Node *p = head, *t = head;
        while (p != nullptr) {
            t = p;
            if (p->child != nullptr) {
                Node *q = p->next;
                t = _flatten(p->child, q);
                p->next = p->child;
                p->child->prev = p;
                p->child = nullptr;
                q = p;
            } else {
                p = p->next;
            }
        }

        t->next = tail;
        if (tail != nullptr) {
            tail->prev = t;
        }

        return head;
    }

    Node* flatten(Node* head) {
        _flatten(head, nullptr);
        return head;
    }
};