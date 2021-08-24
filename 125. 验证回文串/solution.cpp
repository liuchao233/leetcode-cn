#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;

        while (i < j) {
            char l = s[i], r = s[j];

            if (!isalnum(l)) {
                ++i;
            } else if (!isalnum(r)) {
                --j;
            } else if (tolower(l) != tolower(r)) {
                return false;
            } else {
                ++i;
                --j;
            }
        }
        
        return true;
    }
};