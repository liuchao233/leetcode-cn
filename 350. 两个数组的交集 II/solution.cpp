#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
            int num1 = nums1[i], num2 = nums2[j];
            if (num1 == num2) {
                result.push_back(num1);
                ++i;
                ++j;
            } else if (num1 < num2) {
                ++i;
            } else {
                ++j;
            }
        }

        return result;
    }
};