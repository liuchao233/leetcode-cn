#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n < 2) {
            return n;
        }

        // 可变长度的数组可以使用 vector 来表示
        vector<int> nums(n + 1);
        nums[i] = 1;
        for (int i = 2; i < (n + 1); ++i) {
            nums[i] = nums[i / 2] + i % 2 * nums[i / 2 + 1];
        }   

        // 最大的元素可以使用 max_element 算法来计算，不需要重新实现
        return *max_element(nums.begin(), nums.end());
    }
};
