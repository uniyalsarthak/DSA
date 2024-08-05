#include<bits/stdc++.h>
using namespace std;
int main()
{
    int size;
    cout<<"Enter the size of array:";
    cin>>size;
    int x[size];
    for(int j=0;j<size;j++)
    {
        cout<<"Enter element"<<j+1<<":";
        cin>>x[j];
    }
    for(int j=0;j<size-1;j++)
    {
        int a=x[j]&1;
        int b=x[j+1]&1;
        if(a==b)
        {
        cout<<x[j]+1<<"  ";
        }
    }
}