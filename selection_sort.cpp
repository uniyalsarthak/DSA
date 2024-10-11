#include<bits/stdc++.h>
using namespace std;
void selectionSort(int* arr,int n)
{
    for(int i=0;i<n-1;i++)           //check if there is any element greater than a[i]
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[min]>arr[j])
            min=j;
        }
        swap(arr[min],arr[i]);
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
    int arr[n]={2,3,1,5,4};
    selectionSort(arr,n);
    print(arr,n);

}