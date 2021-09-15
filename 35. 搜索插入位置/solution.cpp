#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();

        while (l < r) {
            int mid = (l - r) / 2 + l;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};

int main() {
    Solution solution;
    cout << solution.searchInsert({1}, 0) << endl;
}
