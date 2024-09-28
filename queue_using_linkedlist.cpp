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
Node* front=NULL;
Node* rear=NULL;
void isempty()
{
    if(front==NULL && rear==NULL)
    cout<<"empty"<<endl;
    else
    cout<<"not empty"<<endl;    
}
void enqueue(int value)
{
    Node* temp=new Node(value);
    if(front==NULL && rear==NULL)
    {
        front=temp;
        rear=temp;
    }
    else
    {
        rear->next=temp;
        rear=temp;
    }
}

void dequeue()
{
    if(front==NULL && rear==NULL)
    cout<<"Nothing to dequeue as Queue is empty"<<endl;
    else if(front==rear)
    {
        front=rear=NULL;
        delete front;
    }
    else
    {
        Node* temp=front;
        front=front->next;
        delete temp;
    }
}

void peek()
{
    if(front==NULL && rear==NULL)
    cout<<"Queue is empty"<<endl;
    else
    cout<<front->data<<endl;
}

void displayQueue()
{
    if(front==NULL)
    cout<<"Queue is empty"<<endl;
    else
    {
        Node* temp=front;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }   
        cout<<endl;     
    }
}
int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    dequeue();
    peek();
    displayQueue();
    dequeue();
    dequeue();
    displayQueue();
    dequeue();
    isempty();
}