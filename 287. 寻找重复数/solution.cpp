#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (set.count(num)) {
                return num;
            }
            set.insert(num);
        }
        return -1;
    }
};