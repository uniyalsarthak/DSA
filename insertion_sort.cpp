#include<bits/stdc++.h>
using namespace std;

void insertionSort(int* a,int n)
{
    for(int i=1;i<n;i++)                   //check that previous elements are smaller than current element or not
    {
        int temp=a[i];
        int j=i-1;
        while(j>=0&& a[j]>temp)          
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
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
    int n=6;
    int a[n]={3,6,9,2,5,1};
    insertionSort(a,n);
    print(a,n);
}