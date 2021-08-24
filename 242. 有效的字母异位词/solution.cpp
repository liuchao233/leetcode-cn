#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int alphas[26];

        for (int i = 0; i < 26; ++i) {
            alphas[i] = 0;
        }

        for (auto c : s) {
            ++alphas[c - 'a'];
        }

        for (auto c : t) {
            --alphas[c - 'a'];
        }

        for (int i = 0; i < 26; ++i) {
            if (alphas[i] != 0) {
                return false;
            }
        }

        return true;
    }
};