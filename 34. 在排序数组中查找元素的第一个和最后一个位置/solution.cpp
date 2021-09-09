#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange1(vector<int>& nums, int target) {
        int len = nums.size();

        for (int i = 0; i < len; ++i) {
            if (nums[i] == target) {
                for (int j = i + 1; j < len; ++j) {
                    if (nums[j] != target) {
                        return { i, j - 1 };
                    }
                }
                return { i, len - 1 }; 
            }
        }
        return { -1, -1 };
    }


    // lower 为 true 返回第一个大于等于 target 的下标
    // lower 为 false 返回第一个大于 target 的下标
    // 将满足的条件先保存到 ans 中，如果没有找到就返回空

    int binarySearch(vector<int>& nums, int target, bool lower) {
        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIdx = binarySearch(nums, target, true);
        int rightIdx = binarySearch(nums, target, false) - 1;
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {
            return vector<int>{leftIdx, rightIdx};
        } 
        return vector<int>{-1, -1};
    }
};