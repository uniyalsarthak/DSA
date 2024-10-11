#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int* a,int n)
{
    int swapped=0;
 
    for(int i=0;i<n-1;i++)                //keep swaping adjacent elements untill a[j+1]>a[j]
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            swap(a[j],a[j+1]);
            swapped=1;
        }
        if(swapped==0)                   //if no swap occurred in first iteration means array already sorted
        break;
    }
}

void print(int* arr,int n)
{
    cout<<"Sorted array:";
    for(int k=0;k<n;k++)
    {
        cout<<arr[k]<<" ";
    }
}

int main()
{
    int n=5;
    int a[n]={3,7,5,10,81};
    bubbleSort(a,n);
    print(a,n);
}