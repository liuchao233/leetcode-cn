#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (auto c : s) {
            switch (c) {
                case '(': st.push(')'); break;
                case '{': st.push('}'); break;
                case '[': st.push(']'); break;
                default:
                    if (st.empty()) {
                        return false;
                    }
                
                    if (c == st.top()) {
                        st.pop();
                    } else {
                        return false;
                    }
            }
        }

        return st.empty();
    }
};