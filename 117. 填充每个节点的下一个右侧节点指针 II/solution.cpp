#include <queue>

using namespace std;

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
    
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }

        Node *p = root;
        Node *nextLevelHead = nullptr, *nextLevelP = nullptr;
        while (p != nullptr) {
            if (p->left != nullptr) {
                if (nextLevelHead == nullptr) {
                    nextLevelHead = p->left;
                    nextLevelP = p->left;
                } else {
                    nextLevelP->next = p->left;
                    nextLevelP = nextLevelP->next;
                }
            } 
            
            if (p->right != nullptr) {
                if (nextLevelHead == nullptr) {
                    nextLevelHead = p->right;
                    nextLevelP = p->right;
                } else {
                    nextLevelP->next = p->right;
                    nextLevelP = nextLevelP->next;
                }
            }

            p = p->next;

            if (p == nullptr) {
                p = nextLevelHead;
                nextLevelHead = nullptr;
            }
        }

        return root;
    }


    Node* connect1(Node* root) {
        if (!root) {
            return root;
        }

        queue<Node *> q;
        q.push(root);

        while (!q.empty()) {
            int currentLevelSize = q.size();
            for (int i = 1; i <= currentLevelSize; ++i) {
                auto node = q.front();q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                node->next = (i == currentLevelSize ? nullptr : q.front());
            }
        }

        return root;
    }
};