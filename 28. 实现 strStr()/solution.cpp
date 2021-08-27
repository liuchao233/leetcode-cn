#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystackLen = haystack.size();
        int needleLen = needle.size();

        if (needleLen > haystackLen) {
            return -1;
        }

        if (needleLen == haystackLen) {
            return haystack == needle ? 0 : -1;
        }

        for (int i = 0; i < haystackLen; ++i) {
            
            bool match = true;
            for (int j = 0; j < needleLen; ++j) {
                if (haystack[i + j] != needle[j]) {
                    match = false;
                    break;    
                }
            }

            if (match) {
                return i;
            }
        }

        return -1;
    }
};