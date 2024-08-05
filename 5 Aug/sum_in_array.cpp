#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[6]={1,2,3,7,5,12};
    for(int i=0;i<6;i++)
    {
        for(int j=i+1;j<6;j++)
        {
            for(int k=0;k<6;k++)
            if(arr[i]+arr[j]==arr[k])
            {
                cout<<"("<<arr[i]<<","<<arr[j]<<")  ";
            }
            
        }
    }
}