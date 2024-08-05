#include<bits/stdc++.h>
using namespace std;
int main()
{
    float area=0;
    float max_area=INT_MIN;
    int arr[5]={3,7,4,8,1};
    for(int i=0;i<5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            area+=((arr[i]+arr[j])/2)*(j-i);
            if(area>max_area)
            max_area=area;
        }
    }
    cout<<max_area;
}