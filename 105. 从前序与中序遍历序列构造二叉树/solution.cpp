#include <vector>
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


// 中左右 3,9,20,15,7 
// 左中右 9,3,15,20,7

class Solution {
public:
    TreeNode* build(vector<int>::iterator pbegin, vector<int>::iterator pend, vector<int>::iterator ibegin, vector<int>::iterator iend) {
        if (pbegin == pend) {
            return nullptr;
        }

        TreeNode* rootNode = new TreeNode(*pbegin); ++pbegin;
        vector<int>::iterator imid = find(ibegin, iend, rootNode->val);
        if (imid != iend) {
            vector<int>::iterator ilbegin = ibegin, ilend = imid, irbegin = imid + 1, irend = iend;
            vector<int>::iterator plbegin = pbegin, plend = pbegin + (ilend - ilbegin), prbegin = plend, prend = pend;            

            rootNode->left = build(plbegin, plend, ilbegin, ilend);
            rootNode->right = build(prbegin, prend, irbegin, irend);
        }

        return rootNode;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
};