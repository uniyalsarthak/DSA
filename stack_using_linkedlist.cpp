#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

Node* top=NULL;
class Stack
{
    public:
    void push(int element)
    {
        Node* temp=new Node(element);
        temp->next=top;
        top=temp;
    }

    void pop()
    {
        if(top==NULL)
        cout<<"can't pop as stack is empty"<<endl;
        else
        {
            Node* temp=top;
            top=top->next;
            delete temp;    
        }
    }

    void peek()
    {
        if(top==NULL)
        cout<<"empty stack"<<endl;
        else
        cout<<top->data<<endl;
    }   

    void isempty()
    {
        if(top==NULL)
        cout<<"Stack is empty"<<endl;
        else 
        cout<<"Stack is not empty"<<endl;
    } 
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    s.peek();
    s.isempty();
    s.pop();
    s.pop();
    s.isempty();
    s.pop();
}