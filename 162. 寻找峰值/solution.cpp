#include <vector>

using namespace std;

class Solution {
public:
    // 线性查找
    int findPeakElement1(vector<int>& nums) {
        int len = nums.size();

        for (int i = 1; i < len; ++i) {
            if (nums[i] < nums[i - 1]) {
                return i - 1;
            }
        }
        
        return len - 1;
    }

    // 二分法查找
    int findPeakElement2(vector<int>& nums) {
        return search(nums, 0, nums.size() - 1);    
    }
    
    int search(vector<int> &nums, int l, int r) {
        if (l == r) {
            return l;
        }

        int mid = (r - l) / 2 + l;
        if (nums[mid] > nums[mid + 1]) {
            return search(nums, l, mid);    
        } else {
            return search(nums, mid + 1, r);
        }
    }
};