#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // 防止数组越界
        decltype(nums.size()) len = nums.size(), offset = k % len;
        if (offset == 0) return;
        auto iter = nums.begin() + len - offset;
        reverse(nums.begin(), iter);
        reverse(iter, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
