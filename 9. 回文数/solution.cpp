class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0) {
            return true;
        }
        if (x < 0 || (x % 10 == 0)) {
            return false;
        }

        int revertNumber = 0;
        while (x > revertNumber) {
            revertNumber = revertNumber * 10 + x % 10;
            x /= 10;
        }

        // 处于中位数的字母不影响判断
        return x == revertNumber || x == revertNumber / 10;
    }
};