#include<bits/stdc++.h>
using namespace std;

int pri(char ch)
{
    if(ch == '+' || ch == '-')
        return 1;

    if(ch == '*' || ch == '/')
        return 2;

    return 0;
}

int cal(int a, int b, char ch)
{
    if(ch == '+')
        return a + b;

    if(ch == '-')
        return a - b;

    if(ch == '*')
        return a * b;

    if(ch == '/')
        return a / b;
}

int main()
{
    string s;
    cin >> s;

    stack<int> st;
    stack<char> op;

    for(int i=0; i<s.length(); i++)
    {
        if(isdigit(s[i]))
        {
            int num = 0;

            while(i<s.length() && isdigit(s[i]))
            {
                num = num * 10 + (s[i]-'0');
                i++;
            }

            i--;
            st.push(num);
        }
        else if(s[i] == '(')
        {
            op.push(s[i]);
        }
        else if(s[i] == ')')
        {
            while(op.top() != '(')
            {
                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                char ch = op.top();
                op.pop();

                st.push(cal(a,b,ch));
            }

            op.pop();
        }
        else
        {
            while(!op.empty() && op.top() != '(' &&
                  pri(op.top()) >= pri(s[i]))
            {
                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                char ch = op.top();
                op.pop();

                st.push(cal(a,b,ch));
            }

            op.push(s[i]);
        }
    }

    while(!op.empty())
    {
        int b = st.top();
        st.pop();

        int a = st.top();
        st.pop();

        char ch = op.top();
        op.pop();

        st.push(cal(a,b,ch));
    }

    cout << st.top();

    return 0;
}
