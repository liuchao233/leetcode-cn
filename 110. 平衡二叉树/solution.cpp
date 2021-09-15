#include <algorithm>

using namespace std;

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
    int nodeDepth(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftDepth = nodeDepth(node->left);
        int rightDepth = nodeDepth(node->right);

        if (leftDepth == INT_MAX || rightDepth == INT_MAX) {
            return INT_MAX;
        }

        int delta = rightDepth - leftDepth;
        if (delta > 1 || delta < -1) {
            return INT_MAX;
        } else {
            return max(rightDepth, leftDepth) + 1;
        }
    }

    bool isBalanced(TreeNode* root) {
        return nodeDepth(root) == INT_MAX;
    }
};