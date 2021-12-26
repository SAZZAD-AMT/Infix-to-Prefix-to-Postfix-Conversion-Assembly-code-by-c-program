# Infix-to-Prefix-to-Postfix-Conversion-Assembly

<h1>Infix to Prefix Conversion</h1>
While we use infix expressions in our day to day lives. Computers have trouble understanding this format because they need to keep in mind rules of operator precedence and also brackets. Prefix and Postfix expressions are easier for a computer to understand and evaluate. 
Given two operands a                 and b                 and an operator \odot                 , the infix notation implies that O will be placed in between a and b i.e (a * b)                 . When the operator is placed after both operands i.e ab\odot                 , it is called postfix notation. And when the operator is placed before the operands i.e (* a b)                 , the expression in prefix notation.
Given any infix expression, we can obtain the equivalent prefix and postfix format.


<h1>Infix to Postfix Conversion</h1>
For an assignment, I am required to write an assembly program that will convert an infix string that may consist of +,-,*,/,(,) and their operands. I also the C code from which I have based my assembly code off of. I am working on x86 intel architecture (that is what we are learning in class). The C code works in any case, my assembly code compiles but does not convert the string (for example, I enter 5+5, and 5+5 is returned when it should be 55+). My best guess is that I am not using the stack properly. I will include my main program, my C function, and my assembly code. My question is, obviously, where I am going wrong? Thank you for your time and help.

<h1>1. Write program to generate assembly code from prefix code
2. Generate assembly code from prefix code</h1>


#include<bits/stdc++.h>
#define SIZE 5
using namespace std ;

class stackk
{
private:
    char data [50];
    int top;
public :
    stackk()
    {
        top=0;
    }
    void push(char item)
    {

        data [top]=item;
        top++;
    }
    char getTop()
    {
        return data[top-1];
    }
    char pop()
    {
        if(top==0)
            return '0';
        top--;
        char item=data[top];
        return item;
    }
    int isEmpty()
    {
        if (top==0)
            return 1;
        else
            return 0;
    }
    int getLength()
    {
        return top;
    }
};


void infix_postfix(char * str)
{
    stackk st;
    char temp[30];
    int j=-1;
    int size = strlen(str);

    for(int i=0; i<size; i++)
    {
        if(str[i]!='(' && str[i]!=')' && str[i]!='{' && str[i]!='}' && str[i]!='[' && str[i]!=']' && str[i]!='+' && str[i]!='-' && str[i]!='*' && str[i]!='/')
        {
            temp[++j] = str[i];
        }
        else if(str[i]=='+' || str[i]=='-')
        {
            st.push(str[i]);
        }
        else if(str[i]=='(')
        {
            st.push(str[i]);
        }
        else if(str[i]=='*' || str[i]=='/')
        {
            st.push(str[i]);
        }
        else if(str[i]==')')
        {
            while(1)
            {
                if(st.getTop()=='(')
                {
                    st.pop();
                    break;
                }
                temp[++j] = st.getTop();
                st.pop();
            }
        }
    }
    while(!st.isEmpty())
    {
        temp[++j] = st.getTop();
        st.pop();
    }
      

    int i=-1;
    for(j=0; j<size; j++)
    {
        str[++i]=temp[j];
    }
}

void reverse(char *exp)
{

    int n = strlen(exp);
    for (int i = 0; i < n / 2; i++)
        swap(exp[i], exp[n - i - 1]);
}
void brackets(char * exp)
{
    int n = strlen(exp);
    for (int i = 0; i <=n; i++)
    {
        if(exp[i]=='(')
            exp[i]=')';
        else if(exp[i]==')')
            exp[i]='(';
    }
}


void infix_prefix(char *exp)
{

    reverse(exp);
    brackets(exp);
    infix_postfix(exp);
    reverse(exp);

}

int main (void)
{
    while(1)
    {
        printf("1.Infix to Prefix.  2.Infix to POSTFIX.\n5.Exit\n");
        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            char str[30];
            printf("Infix Expression : ");
            cin >> str;
            infix_prefix(str);

            printf("Prefix Expression : ");
            cout<<str;
            printf("\n");
        }
        else if(ch==2)
        {
            char exp[30];
            printf("Infix Expression : ");
            cin >> exp;

            infix_postfix(exp);
            printf("Postfix Expression : ");
            cout<<exp;
            printf("\n");
        }
        else if(ch==5)
            break;
    }
}
