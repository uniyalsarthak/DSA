#include<bits/stdc++.h>
using namespace std;
int a[10],size,key;
int binarysearch(int low,int high)
{
    if(low>high)
        return 0;
    else
    {
        int mid=low +(high-low)/2;
        if(a[mid]==key)
        return mid;
        else
        {
            if(key>a[mid])
            return binarysearch(low+1,high);
            else
            return binarysearch(low,high-1);
        }
    }
        

    return -1;
}
int main()
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
    int found=binarysearch(0,size-1);
    if(found==-1 )
    cout<<"key not present";
    else
    cout<<"key present at index "<<found;
}