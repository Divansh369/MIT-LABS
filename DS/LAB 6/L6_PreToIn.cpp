#include <iostream>
using namespace std;
#include <stack>
#include <stdlib.h>

double evaluatePrefix(string exp)
{
    stack<double> Stack;
    for (int j = exp.size() - 1; j >= 0; j--) {
        char c=exp[j];
		if (c >= '0' && c <= '9') {
            Stack.push(c - '0');
		}
        else {
            double x = Stack.top();
            Stack.pop();
            double y = Stack.top();
            Stack.pop();
            if (c == '+') {
                Stack.push(y + x);
            }
            else if (c == '-') {
                Stack.push(y - x);
            }
            else if (c == '*') {
                Stack.push(y * x);
            }
            else if (c == '/') {
                Stack.push(y / x);
            }
        }
    }
    return Stack.top();
}
int main()
{
    char exp[500];
    cout<<"Enter a prefix expression: ";
    cin>>exp;
    cout<<"\nResult after evaluation: "<<evaluatePrefix(exp);
    return 0;
}
