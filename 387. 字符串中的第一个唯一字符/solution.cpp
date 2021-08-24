#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int alphas[26];

        for (int i = 0; i < 26; ++i) {
            alphas[i] = 0;
        }

        for (auto c : s) {
            ++alphas[c - 'a'];
        }

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (alphas[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};