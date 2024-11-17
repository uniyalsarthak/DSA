#include<bits/stdc++.h>
using namespace std;
int partition(int* a,int s,int e)
{
    int count=0;
    int pivot=a[s];
    for(int i=s+1;i<=e;i++)
    {
        if(a[i]<pivot)
        count++;
    }
    int pivotIndex=s+count;
    swap(a[s],a[pivotIndex]);
    int i=s,j=e;
    while(i<pivotIndex && j>pivotIndex)
    {
        while(a[i]<pivot)
        i++;
        while(a[j]>pivot)
        j--;
        if(i<pivotIndex && j>pivotIndex)
        swap(a[i++],a[j--]);
    }
    return pivotIndex;
}

int kth_smallest(int* a,int low,int high,int k)
{
    int j=partition(a,low,high);
    if(j+1==k)
    return a[j+1];
    else if(k>j+1)
    kth_smallest(a,j+1,high,k);
    else
    kth_smallest(a,low,j-1,k);
}

int main()
{
    int k=2;
    int arr[5]={8,10,3,2,7};
    int i=kth_smallest(arr,0,4,k);
    cout<<i;
}