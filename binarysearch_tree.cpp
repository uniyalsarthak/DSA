#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node* BST(node* &root,int d)
{
    if(root==NULL)
    {
        root=new node(d);
        return root;
    }
    if(d>root->data)
    root->right=BST(root->right,d);
    if(d<root->data)
    root->left=BST(root->left,d);
    return root;
}
void insertData(node* &root)
{
    int d;
    cout<<"enter data:";
    cin>>d;
    while(d!=-1)
    {
        BST(root,d);
        cout<<"enter data:";
        cin>>d;
    }
}

void bft(node* &root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            cout<<endl;           // the whole level is traversed
            if(!q.empty())
            q.push(NULL);                                                    
        }         
        else
        {
            cout<<temp->data<<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

bool isPresentBST(node* &root,int x)
{
    // if(root==NULL)
    // return false;
    // if(root->data==x)
    // return true;
    // if(root->data<x)
    // return isPresentBST(root->right,x);
    // if(root->data>x)
    // return isPresentBST(root->left,x);


    node* temp=root;
    while(temp!=NULL)
    {
        if(temp->data==x)
        return true;
        if(temp->data<x)
        temp=temp->right;
        if(temp->data>x)
        temp=temp->left;
    }
    return false;
}

node* max(node* temp)
{
    while(temp->right!=NULL)
    temp=temp->right;
    return temp;
}
node* min(node* temp)
{
    while(temp->left!=NULL)
    temp=temp->left;
    return temp;
}

node* deleteNode(node* root,int x)
{
    if(root==NULL)
    return root;

    if(root->data==x)
    {
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }

        if(root->left!=NULL && root->right==NULL)
        {
            node* temp=root->left;
            delete root;
            return temp;
        }

        if(root->left==NULL && root->right!=NULL)
        {
            node* temp=root->right;
            delete root;
            return temp;
        }

        if(root->left!=NULL && root->right!=NULL)
        {
            node* pred=max(root->left);
            root->data=pred->data;
            root->left=deleteNode(root->left,pred->data);
            return root;
        }
    }

    else if(x>root->data)
    {
        root->right=deleteNode(root->right,x);
        return root;
    }

    else if(x<root->data)
    {
        root->left=deleteNode(root->left,x);
        return root;
    }
}

int main()
{
    node* root=NULL;
    //insertData(root);
    vector<int> arr={2,7,4,9,5,8};
    for(int i=0;i<arr.size();i++){
        root=BST(root,arr[i]);
    }
    bft(root);
    if(isPresentBST(root,5)){
        cout<<"Node is present"<<endl;
    }
    else
    cout<<"Node is not present"<<endl;
    deleteNode(root,9);
    bft(root);

}