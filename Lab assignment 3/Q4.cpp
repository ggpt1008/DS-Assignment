#include <iostream>
#include <cctype>
#include <string>
#include <stack>
using namespace std;

int priority(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '^') return 3;
    return 0;
}

string infixToPostfix(string str) {
    string result;
    stack<char> st;

    for (char ch : str) {
        if (isalnum(ch)) {
            result += ch;
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) 
            st.pop(); // remove '('
        }
        else { // operator
            while (!st.empty() && priority(st.top()) >= priority(ch)) {
                result += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    return result;
}

int main() {
    string infix = "(A+(B*(C-D)/E))";
    cout << "Postfix: " << infixToPostfix(infix) << endl;
    return 0;
}