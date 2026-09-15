#include <iostream>
#include <stack>
#include <string>
using namespace std;

int priority(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

string infixToPostfix(string infix)
{
    stack<char> s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        // Operand
        if (isalnum(ch))
        {
            postfix = postfix + ch;
        }

        // Opening bracket
        else if (ch == '(')
        {
            s.push(ch);
        }

        // Closing bracket
        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix = postfix + s.top();
                s.pop();
            }

            if (!s.empty())
                s.pop();
        }

        // Operator
        else
        {
            while (!s.empty() && s.top() != '(' &&
                   priority(s.top()) >= priority(ch))
            {
                postfix = postfix + s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    // Remove remaining operators
    while (!s.empty())
    {
        postfix = postfix + s.top();
        s.pop();
    }

    return postfix;
}

int main()
{
    string infix;

    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Postfix expression: ";
    cout << infixToPostfix(infix);

    return 0;
}
