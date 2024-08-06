#include<bits/stdc++.h>
using namespace std;
bool linear_search(int a[],int size)
{
    cout<<"enter the size of array:";
    cin>>size;
     for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }

    int x;
    cout<<"enter the number to be searched=";
    cin>>x;
    for(int i=0;i<size;i++)
    {
        if(a[i]==x)
        return 1;
    }
    return 0;
}
int main()
{
    int a[10],size;
     bool found=linear_search(a,size);
     if(found==0)
    cout<<"not found";
    else
    cout<<"found";
}
