
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<int> st;
    int minVal;

public:
    MinStack() {
        minVal = 0;
    }

    void push(int x) {
        if (st.empty()) {
            st.push(x);
            minVal = x;
        }
        else if (x >= minVal) {
            st.push(x);
        }
        else {
            // Store modified value (2*x - minVal)
            int temp = 2*x - minVal;
            st.push(temp);
            minVal = x;   // update minimum
        }
    }

    void pop() {
        if (st.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }

        int topVal = st.top();
        st.pop();

        if (topVal < minVal) {
            // topVal is modified; decode previous min
            int previousMin = 2*minVal - topVal;
            minVal = previousMin;
        }
    }

    int top() {
        if (st.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        int topVal = st.top();
        if (topVal < minVal) {
            return minVal;   // encoded top, true value is minVal
        }
        return topVal;
    }

    int getMin() {
        if (st.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return minVal;
    }
};

int main() {
    MinStack st;

    st.push(5);
    st.push(2);
    st.push(8);
    st.push(1);

    cout << "Min: " << st.getMin() << endl; // 1
    st.pop();
    cout << "Min: " << st.getMin() << endl; // 2
    cout << "Top: " << st.top() << endl;    // 8

    return 0;
}

