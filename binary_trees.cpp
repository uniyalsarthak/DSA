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
node* root=NULL;
node* buildTree(node* root)
{
    cout<<"Enter the data:";
    int data;
    cin>>data;
    root =new node(data);
    if(data==-1) return NULL;
    cout<<"Enter data to insert at left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter data to insert at right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}

node* generation(vector<int> &arr)
{
    if(arr.empty()) return NULL;
    queue<node*> q;
    node* root=new node(arr[0]);
    q.push(root);
    int i=1;
    while(i<arr.size())
    {
        node* temp=q.front();
        q.pop();
        if(i<arr.size())
        {
            temp->left=new node(arr[i++]);
            q.push(temp->left);
        }

        if(i<arr.size())
        {
            temp->right=new node(arr[i++]);
            q.push(temp->right);
        }
    }
    return root;
}
void bft(node* root)
{
    if (root == NULL) {
        return;
    }
    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();

            cout<<temp->data<<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
    }
}

void dft(node* root)
{
    if(root==NULL) return ;
    cout<<root->data<<" ";
    dft(root->left);
    dft(root->right);
}

void inorderTraversal(node* root)
{
    if(root==NULL) return ;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void postorderTraversal(node* root)
{
    if(root==NULL) return ;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}

int main()
{
    vector<int> arr={3,6,2,6,8};
   // root=buildTree(root);
   root=generation(arr);
    cout<<"BreadthFirstTraversal:";
    bft(root);cout<<endl;
    cout<<"DepthFirstTraversal:";
    dft(root);cout<<endl;
    cout<<"PostTraversal:";
    postorderTraversal(root);cout<<endl;
    cout<<"InorderTraversal:";
    inorderTraversal(root);cout<<endl;
}
//2 1 3 -1 -1 7 -1 -1 5 -1 6 -1 -1