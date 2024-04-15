
#include <iostream>
using namespace std;
#include <stack>
#include <algorithm>

bool isOperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
string infixToPostfix(string infix)
{
    infix = '(' + infix + ')';
    int l = infix.size();
    stack<char> char_stack;
    string output;
 
    for (int i = 0; i < l; i++) {
        if (isalpha(infix[i]) || isdigit(infix[i]))
            output += infix[i];
        else if (infix[i] == '(')
            char_stack.push('(');
        else if (infix[i] == ')') {
            while (char_stack.top() != '(') {
                output += char_stack.top();
                char_stack.pop();
            }
            char_stack.pop();
        }
        else
        {
            if (isOperator(char_stack.top()))
            {
                if(infix[i] == '^')
                {
                      while (prec(infix[i]) <= prec(char_stack.top()))
                       {
                         output += char_stack.top();
                         char_stack.pop();
                       }
                     
                }
                else
                {
                    while (prec(infix[i]) < prec(char_stack.top()))
                       {
                         output += char_stack.top();
                         char_stack.pop();
                       }                     
                }
                char_stack.push(infix[i]);
            }
        }
    }
      while(!char_stack.empty()){
          output += char_stack.top();
        char_stack.pop();
    }
    return output;
}
string infixToPrefix(string infix)
{
    int l = infix.size();
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < l; i++) {
 
        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
    string prefix = infixToPostfix(infix);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}
int main()
{
    string exp;
    cout<<"Enter an infix expression: ";
    cin>>exp;
    cout<<"\nPrefix expression: "<<infixToPrefix(exp);
    return 0;
}
