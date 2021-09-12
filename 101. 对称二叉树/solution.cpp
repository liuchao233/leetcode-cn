struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric1(TreeNode* left, TreeNode* right) {
        if (!left && !right) {
            return true;
        }

        if (!left || !right) {
            return false;
        }

        if (left->val == right->val) {
            return isSymmetric1(left->left, right->right) && isSymmetric1(left->right, right->left);  
        }

        return false;
    }

    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }

        if (left != nullptr && right != nullptr && left->val == right->val) {
            return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);            
        } 

        return false;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        return isSymmetric(root->left, root->right);
    }
};