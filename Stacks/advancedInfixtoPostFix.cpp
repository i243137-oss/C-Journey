#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int outStackPre(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 3;
    if (x == '^') return 6;
    if (x == '(') return 7;
    if (x == ')') return 0;
    return -1;
}

int inStackPre(char x) {
    if (x == '+' || x == '-') return 2;
    if (x == '*' || x == '/') return 4;
    if (x == '^') return 5;
    if (x == '(') return 0;
    return -1;
}

bool isOperand(char x) {
    return !(x=='+' || x=='-' || x=='*' || x=='/' || x=='^' || x=='(' || x==')');
}

char* infixToPostfix(char* exp) {
    stack<char> st;
    char* postfix = new char[strlen(exp) + 1];
    int i = 0, j = 0;

    while (exp[i] != '\0') {
        if (isOperand(exp[i])) {
            postfix[j++] = exp[i++];
        }
        else if (exp[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix[j++] = st.top();
                st.pop();
            }
            st.pop();
            i++;
        }
        else {
            while (!st.empty() && inStackPre(st.top()) >= outStackPre(exp[i])) {
                postfix[j++] = st.top();
                st.pop();
            }
            st.push(exp[i]);
            i++;
        }
    }

    while (!st.empty()) {
        postfix[j++] = st.top();
        st.pop();
    }

    postfix[j] = '\0';
    return postfix;
}

int main() {
    char exp[] = "((a+b)*c)-d^e^f";
    cout << infixToPostfix(exp);
    return 0;
}
