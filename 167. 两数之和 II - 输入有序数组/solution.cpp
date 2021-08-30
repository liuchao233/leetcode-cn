#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() -1;
        
        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (target < sum) {
                ++left;
            } else if (target > sum) {
                --right;
            } else {
                return {left + 1, right + 1};
            }
        }

        return {-1, -1};
    }

    vector<int> twoSum1(vector<int>& numbers, int target) {
        int n = numbers.size();
        
        for (int i = 0; i < n; ++i) {
            int expect = numbers[i];
            int left = i + 1, right = n;
            
            while (left < right) {
                int mid = (right - left) / 2 + left;
                
                if (numbers[mid] < expect) {
                    left = mid + 1;
                } else if (numbers[mid] > expect) {
                    right = mid;
                } else {
                    return {i + 1, mid + 1};      
                }
            }
        }

        return {-1, -1};
    }
};