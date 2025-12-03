#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    stack<int> st;

    int n = q.size();
    int expected = 1;   

    while (!q.empty()) {

        if (q.front() == expected) {   // send directly to output
            q.pop();
            expected++;
        }
        else if (!st.empty() && st.top() == expected) {  // take from stack
            st.pop();
            expected++;
        }
        else {                         
            st.push(q.front());
            q.pop();
        }
    }

    // Empty remaining stack
    while (!st.empty() && st.top() == expected) {
        st.pop();
        expected++;
    }

    if (expected == n + 1)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
