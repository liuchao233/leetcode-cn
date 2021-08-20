#include <stack>

using namespace std;

class MinStack {
public:
    stack<int> _min, _normal;

    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        _normal.push(x);

        if (_min.empty() || x <= min()) {
            _min.push(x);
        }
    }
    
    void pop() {
        if (top() == min()) {
            _min.pop();
        }

        _normal.pop();
    }
    
    int top() {
        return _normal.top();
    }
    
    int min() {
        return _min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
