#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        decltype(nums.size()) last = 0;
        for (decltype(nums.size()) i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[last]) {
                nums[++last] = nums[i];
            }
        }
        return nums.size() == 0 ? 0 : last + 1;
    }
};

int main() {

    Solution solution = Solution();

    vector<int> v1{1,1,2};
    cout << solution.removeDuplicates(v1) << endl; // 2

    vector<int> v2{0,0,1,1,1,2,3,3,4};
    cout << solution.removeDuplicates(v2) << endl; // 5

    return 0;
}