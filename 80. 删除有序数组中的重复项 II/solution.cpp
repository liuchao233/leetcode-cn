#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            int sub_count = 0;
            for (;i < nums.size(); ++i) {
                if (nums[i] != num) {
                    --i;
                    break;
                } else if (sub_count < 2) {
                    nums[count++] = nums[i];
                    ++sub_count;
                }
            }
        } 

        return count;
    }
};