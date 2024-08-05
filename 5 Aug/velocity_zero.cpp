#include<bits/stdc++.h>
using namespace std;
int main()
{
     float v;
    cout<<"Enter the velocity of ball:";
     cin>>v;
    int count=0;
    while(v>0.0001)
    {
        v=v/2;
       count++;
    }
    cout<<"Number of bounces="<<count;
}

