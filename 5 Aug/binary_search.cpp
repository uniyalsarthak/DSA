#include<bits/stdc++.h>
using namespace std;
//binary search
int elementsearch(int a[],int size,int key)
{
    cout<<"enter the size of array:";
    cin>>size;
    cout<<"enter a sorted array:";
     for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    cout<<"enter the number to be searched=";
    cin>>key;
    int low=0;
    int high=size-1;
    while(low<=high)
    {
        int mid=low +(high-low)/2;
        if(a[mid]==key)
        return 1;
        else
        {
            if(key>a[mid])
            low=mid+1;
            else
            high=mid-1;
        }
    }
    return -1;
}
int main()
{
    int x;
    int a[10],size;
    int found=elementsearch(a,size,x);
    if(found==1)
    cout<<"key found";
    else
    cout<<"key not found";
}