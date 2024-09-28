#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
Node* head=NULL;
class Linklist{
    public:
    void insert_start(int d)
    {
        if(head==NULL)
    {
        Node* newnode=new Node(d);
        head=newnode;
    }
    
    else
    {
        Node* temp=new Node(d);
        temp->next=head;
        head=temp;
    }

    }

    void insert_end(int d)
    {
        Node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        Node* new_node=new Node(d);
        temp->next=new_node;
    }

    void print_list()
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

    void insert_at_index(int pos,int d)
    {
        Node* temp=head;
        int i=1;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        Node* new_node=new Node(d);
        new_node->next=temp->next;
        temp->next=new_node;
    }

    void delete_at_start()
    {
        Node* temp=head;
        head=head->next;
        delete temp;
    }

    void delete_at_end()
    {
        Node* temp=head;
        Node* prev;
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        delete temp;
    }
    
    void delete_at_index(int pos)
    {
        Node* temp=head;
        Node* prev=NULL;
        int i=1;
        while(i<pos)
        {
            prev=temp;
            temp=temp->next;
            i++;
        }
        prev->next=temp->next;
        delete temp;
    }
};
int main()
{
    Linklist l;
    Node* head=NULL;
    l.insert_start(30);
    l.insert_start(40);
    l.insert_end(20);
    l.print_list();
    cout<<endl;
    l.insert_end(60);
    l.insert_at_index(4,50);
    l.print_list();
    cout<<endl;
    l.delete_at_start();
    l.delete_at_end();
    l.print_list();
    cout<<endl;
    l.delete_at_index(3);
    l.print_list();
}