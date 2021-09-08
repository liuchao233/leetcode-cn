#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();

        while (l < r) {
            int mid = (r - l) / 2 + l;
            int midVal = nums[mid];

            if (midVal == target) {
                return mid;
            } else if (midVal > target) {
                // 中点在左区间
                if (midVal > nums[l]) {
                    // target 比左边最小值还要小，说明在右区间
                    if (target < nums[l]) {
                        l = mid + 1;
                    } else {
                        // target 在左区间
                        r = mid;
                    }
                } else {
                    // 中点在右区间
                    r = mid;
                }
            } else {
               // 中点在左区间
                if (midVal > nums[l]) {
                    l = mid + 1;
                } else {
                    // 中点在右区间
                    // 如果 target 比左边的最大值还要大，则在左侧寻找
                    if (target > nums[r - 1]) {
                        r = mid;  
                    } else {
                        l = mid + 1;
                    }                    
                }
            }
        }

        return -1;
    }
};