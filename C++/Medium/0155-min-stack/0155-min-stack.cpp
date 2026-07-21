#include <stack>
#include <limits>

class MinStack {
public:
    std::stack<long long> st;
    long long currentMin;

    MinStack() {
        currentMin = std::numeric_limits<long long>::max();
    }

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            currentMin = val;
        } else {
            if (val >= currentMin) {
                st.push(val);
            } else {
                st.push(2LL * val - currentMin);
                currentMin = val;
            }
        }
    }

    void pop() {
        if (st.empty()) {
            return;
        }

        long long poppedVal = st.top();
        st.pop();

        if (poppedVal < currentMin) {
            currentMin = 2 * currentMin - poppedVal;
        }
        if (st.empty()) {
            currentMin = std::numeric_limits<long long>::max();
        }
    }

    int top() {
        if (st.empty()) {
            return -1;
        }

        long long topElement = st.top();
        if (topElement >= currentMin) {
            return static_cast<int>(topElement);
        } else {
            return static_cast<int>(currentMin);
        }
    }

    int getMin() {
        if (st.empty()) {
            return -1;
        }
        return static_cast<int>(currentMin);
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */