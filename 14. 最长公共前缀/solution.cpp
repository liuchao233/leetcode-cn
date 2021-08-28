#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }

        int shortestStrIdx = 0;
        for (int i = 1; i < strs.size(); ++i) {
            if (strs[i].size() < strs[shortestStrIdx].size()) {
                shortestStrIdx = i;
            }
        }
        
        string shortestStr = strs[shortestStrIdx];

        for (int i = 0; i < shortestStr.size(); ++i) {
            char c = shortestStr[i];

            for (auto str : strs) {
                if (c != str[i]) {
                    return shortestStr.substr(0, i);
                }                
            }
        }

        return shortestStr;
    }
};