#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMin1(vector<int>& nums) {
        int len = nums.size();

        for (int i = 1; i < len; ++i) {
            if (nums[i] < nums[i - 1]) {
                return nums[i];
            }
        }

        return nums[0];
    }

    int findMin2(vector<int>& nums) {
        return search(nums, 0, nums.size());
    }

    int search(vector<int>& nums, int l, int r) {
        if ((r - l) == 1) {
            return nums[l];
        }

        int mid = (r - l) / 2 + l;
        if (nums[mid] < nums[mid - 1]) {
            return nums[mid];
        } else {
            return min(search(nums, l, mid), search(nums, mid, r));
        }
    }
};