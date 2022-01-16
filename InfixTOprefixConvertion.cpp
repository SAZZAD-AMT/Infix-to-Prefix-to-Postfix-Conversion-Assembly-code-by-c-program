#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}

int getPriority(char C)
{
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}

string infixToPostfix(string infix)
{
    infix = '(' + infix + ')';
    int l = infix.size();
    stack<char> st;
    string v;

    for (int i = 0; i < l; i++) {

        if (isalpha(infix[i]) || isdigit(infix[i]))
            v += infix[i];

        else if (infix[i] == '(')
            st.push('(');

        else if (infix[i] == ')') {
            while (st.top() != '(')
            {
                v += st.top();
                st.pop();
            }
            st.pop();
        }

        else {
            if (isOperator(st.top()))
             {
                while (getPriority(infix[i])  <= getPriority(st.top())) 
                {
                    v += st.top();
                    st.pop();
                }
                st.push(infix[i]);
            }
        }
    }
    return v;
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
    while (1)
    {
        cout << "1.Infix to Prefix.  2.Infi1x to POSTFIX.\n3.Exit\nSELECT NUMBER : ";
        int ch;
        scanf("%d", &ch);
        if (ch == 1)
        {
            string str;
            printf("Infix Expression : ");         
            cin >> str;
            cout <<"Prefix Expression="<< infixToPrefix(str) <<endl ; 

        }
        else if (ch == 2)
        {
            string exp;
            printf("Infix Expression : ");
            cin >> exp;
            cout <<"Postfix Expression="<< infixToPostfix(exp) <<endl ;
            
        }
        else if (ch == 3)
            break;
    }
}
// # (A+B)*(C+D)
// A+(B*C)  (a+(((c*f)-d)*e)+(b*c)+(q-(r/g)))
// (((A/B)+(B*C))-E)
// (A+((B*C)/(E-F)))

