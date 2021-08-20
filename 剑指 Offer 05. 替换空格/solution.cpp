#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string replaceSpace1(string s) {
        string result;
        for (auto c : s) {
            if (isspace(c)) {
                result += "%20";
            } else {
                result += c;
            }
        }
        return result;
    }

    string replaceSpace(string s) {
        decltype(s.size()) count = 0, len = s.size();
        for (auto c : s) {
            if (isspace(c)) {
                ++count;
            }
        }

        if (count == 0) {
            return s;
        }

        s.resize(len + 2 * count);

        for (int i = len - 1, j = s.size() - 1; i >= 0; --i) {
            auto c = s[i];
            if (!isspace(c)) {
                s[j--] = c;
            } else {
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';
            }
        }

        return s;
    }
};