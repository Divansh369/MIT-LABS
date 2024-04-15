#include <iostream>
#include <string.h>
#include <stack>
using namespace std;
 
int evaluatePostfix(string exp)
{
    stack<int> stack;
    for (int j = 0; j <exp.size(); j++) {
        char c=exp[j];
		if (c >= '0' && c <= '9') {
            stack.push(c - '0');
        }
        else {
            int x = stack.top();
            stack.pop();
            int y = stack.top();
            stack.pop();
            if (c == '+') {
                stack.push(y + x);
            }
            else if (c == '-') {
                stack.push(y - x);
            }
            else if (c == '*') {
                stack.push(y * x);
            }
            else if (c == '/') {
                stack.push(y / x);
            }
        }
    }
    return stack.top();
}
int main()
{
    char exp[500];
    cout<<"Enter a postfix expression: ";
    cin>>exp;
    cout<<"\nResult after evaluation: "<<evaluatePostfix(exp);
    return 0;
}
