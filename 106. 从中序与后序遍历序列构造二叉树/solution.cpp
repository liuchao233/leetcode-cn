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


class Solution {
public:
    TreeNode* build(vector<int>::iterator ibegin, vector<int>::iterator iend, vector<int>::reverse_iterator pbegin, vector<int>::reverse_iterator pend) {
        if (pbegin == pend) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(*pbegin); ++pbegin;
        vector<int>::iterator imid = find(ibegin, iend, root->val);
        if (imid != iend) {
            // 中序遍历划分左右 左: ibegin - imid, 右：imid + 1 - iend
            // 后序遍历划分左右 右：pbegin - pbegin + (iend - (imid + 1)) 左 pbegin + (iend - (imid + 1)) - pend
            vector<int>::iterator ilbegin = ibegin, ilend = imid, irbegin = imid + 1, irend = iend; 
            vector<int>::reverse_iterator prbegin = pbegin, prend = pbegin + (irend - irbegin), plbegin = prend, plend = pend; 

            root->left = build(ilbegin, ilend, plbegin, plend);
            root->right = build(irbegin, irend, prbegin, prend);
        }

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder.begin(), inorder.end(), postorder.rbegin(), postorder.rend());
    }
};
