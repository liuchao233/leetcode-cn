#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool getSearchPath(TreeNode *root, TreeNode *target, vector<TreeNode*> &path) {
        if (root == nullptr) {
            return false;
        }

        if (root == target) {
            path.push_back(root);
            return true;
        } else if (getSearchPath(root->left, target, path)){
            path.push_back(root);
            return true;
        } else if (getSearchPath(root->right, target, path)) {
            path.push_back(root);
            return true;
        }

        return false;
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pPath, qPath;
        getSearchPath(root, p, pPath);
        getSearchPath(root, q, qPath);

        vector<TreeNode*>::reverse_iterator pBegin = pPath.rbegin(), pEnd = pPath.rend(), qBegin = qPath.rbegin(), qEnd = qPath.rend();
        TreeNode* ret = *pBegin;
        
        while (pBegin != pEnd && qBegin != qEnd) {
            if (*pBegin == *qBegin) {
                ret = *pBegin;
            } else {
                break;
            }
            ++pBegin;
            ++qBegin; 
        }

        return ret;
    }
};