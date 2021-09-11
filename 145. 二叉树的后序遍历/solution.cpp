#include <vector>

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
    vector<int> postorderTraversal(TreeNode* root, vector<int> &ret) {
        if (root == nullptr) {
            return ret;
        }

        postorderTraversal(root->left, ret);
        postorderTraversal(root->right, ret);
        ret.push_back(root->val);
        return ret;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        return postorderTraversal(root, ret);
    }
};