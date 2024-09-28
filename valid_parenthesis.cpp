#include<bits/stdc++.h>
using namespace std;

int main() {
    stack <char> s;
    string str;
    
    cout << "Enter the string with parentheses: ";
    cin >> str;
    
    for (int i=0;i<str.length();i++)
    {
        char ch=str[i];
        if (ch == '(' || ch == '{' || ch == '[') 
        {
            s.push(ch);
        } 
        else if (ch == ')' || ch == '}' || ch == ']') 
        {
            if (s.empty()) 
            {
                cout << "Not valid";
            }
            if ((ch == ')' && s.top() == '(') || (ch == '}' && s.top() == '{') || (ch == ']' && s.top() == '[')) 
                {
                    s.pop(); 
                } 
            else 
            {
                break;
            }
        }
    }
    
    if (s.empty()) 
    cout << "Valid";
    else 
     cout << "Not valid"; 

}
