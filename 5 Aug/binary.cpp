#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//binary search
int elementsearch(int a[],int key)
{
    int low=0;
    int high=4;
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
    int a[5]={2,5,7,8,10};
    int found=elementsearch(a,3);
    if(found==1)
    cout<<"key found";
    else
    cout<<"key not found";
}