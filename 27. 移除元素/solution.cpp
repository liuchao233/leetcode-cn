#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                ++count;
            }
        }

        for (int i = 0, j = 0; i < nums.size() && j < count; ++i) {
            if (nums[i] != val) {
                nums[j++] = nums[i];
            }
        }

        return count;
    }
};