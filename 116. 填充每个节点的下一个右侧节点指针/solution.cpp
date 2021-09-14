class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    void connectNNext(Node* node, Node* parent, bool isLeft) {
        if (node == nullptr) {
            return;
        }

        if (isLeft) {
            node->next = parent->right;
        } else {
            if (parent->next) {
                node->next = parent->next->left;
            }
        }

        connectNNext(node->left, node, true);
        connectNNext(node->right, node, false);
    }

    Node* connect(Node* root) {
        if (root != nullptr) {
            connectNNext(root->left, root, true);
            connectNNext(root->right, root, false);
        }        
    
        return root;
    }
};