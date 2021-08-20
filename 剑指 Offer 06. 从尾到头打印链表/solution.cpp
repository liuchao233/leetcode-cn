#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> vec;
        auto node = head;

        while (node != NULL) {
            vec.push_back(node->val);
            node = node->next;            
        }
        
        reverse(vec.begin(), vec.end());
        return vec;
    }
};