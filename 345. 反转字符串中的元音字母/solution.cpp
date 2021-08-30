#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            || (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'); 
    }

    string reverseVowels(string s) {
        int i = 0, j = s.length();

        while (i < j) {
            if (!isVowel(s[i])) {
                ++i;
            } else if (!isVowel(s[j])) {
                --j;
            } else {
                swap(s[i], s[j]);
                ++i;
                --j;
            }
        }

        return s;
    }
};