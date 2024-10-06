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
    reverse(str1.begin(), str1.end());
    for(int i=0;i<str1.length();i++)
    {
        char ch=str1[i];
        if(isalnum(ch))
        str2=str2+ch;
        
        else if(ch==')')
        {
            s.push(ch);
        }

        else if(ch=='(')
        {
            while(s.top()!=')')
            {
                str2=str2+s.top();
                s.pop();
            }
            s.pop();
        }

        else
        {
            while(!s.empty() && precedence(ch)<precedence(s.top()))
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
    reverse(str2.begin(), str2.end());
    return str2;
}
int main()
{
    string str;
    cout<<"Enter the infix expression: ";
    cin>>str;
    string prefix=infixToPostfix(str);
    cout<<"Prefix expression: "<<prefix<<endl;
}