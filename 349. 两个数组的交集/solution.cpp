#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int len1 = nums1.size(), len2 = nums2.size();
        int i = 0, j = 0;
        
        vector<int> ret;
        while (i < len1 && j < len2) {
            int num1 = nums1[i], num2 = nums2[j];
            if (num1 == num2) {
                int lastSize = ret.size();
                if (lastSize == 0 || ret[lastSize - 1] != num1) {
                    ret.push_back(num1);
                }
                ++i;
                ++j;
            } else if (num1 < num2) {
                ++i;
            } else {
                ++j;
            }
        }

        return ret;
    }
};