#include<bits/stdc++.h>
using namespace std;
int precedence(char c)
{
    if(c=='*' || c=='/')
    return 2;
    if(c=='+' || c=='-')
    return 1;
    return 0;
}
string infixToPostfix(string str1)
{
    stack <char> s;
    string str2="";
    for(int i=0;i<str1.length();i++)
    {
        char ch=str1[i];
        if(isalnum(ch))
        str2=str2+ch;
        
        else if(ch=='(')
        s.push(ch);

        else if(ch==')')
        {
            while(s.top()!='(')
            {
                str2=str2+s.top();
                s.pop();
            }
            s.pop();
        }

        else
        {
            while(!s.empty() && precedence(ch)<=precedence(s.top()))
            {
                str2=str2+s.top();
                s.pop();                
            }
            s.push(ch);
        }
    }
    while(!s.empty())
    {
        str2=str2+s.top();
        s.pop();
    }
    return str2;
}
void evaluate(string str)
{
    stack <int> s;
    for(int i=0;i<str.length();i++)
    {
        char ch=str[i];
        if(isdigit(ch))
        s.push(ch-'0');
        
        else
        {
            int second_op=s.top();
            s.pop();
            int first_op=s.top();
            s.pop();
            switch (ch)
            {
                case '+':
                s.push(first_op+second_op);
                break;

                case '-':
                s.push(first_op-second_op);
                break;

                case '*':
                s.push(first_op*second_op);
                break;

                case '/':
                s.push(first_op/second_op);
                break;    

                default:
                    break;
            }
        }
    }
    cout<<s.top();
}
int main()
{
    string str;
    cout<<"Enter the infix expression: ";
    cin>>str;
    string postfix=infixToPostfix(str);
    cout<<"Postfix expression: "<<postfix<<endl;
    cout<<"Evaluated Postfix expression: ";
    evaluate(postfix);
}