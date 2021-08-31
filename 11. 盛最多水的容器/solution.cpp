#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int calcArea(vector<int>& height, int left, int right) {
        int lower = min(height[left], height[right]);
        return lower * (right - left);
    }

    int maxArea(vector<int>& height) {
        int ret = 0;
        int left = 0, right = height.size() - 1;

        while (left < right) {
            ret = max(calcArea(height, left, right), ret);
            if (height[left] <= height[right]) {
                ++left;
            } else {
                --right;
            }
        }

        return ret;
    }
};