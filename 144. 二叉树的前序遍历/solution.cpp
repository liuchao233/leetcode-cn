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
    vector<int> preorderTraversal(TreeNode* root, vector<int> &ret) {
        if (root == nullptr) {
            return ret;
        }

        ret.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return ret;
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        return preorderTraversal(root, ret);
    }
};