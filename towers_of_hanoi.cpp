#include<bits/stdc++.h>
using namespace std;
void toi(int n,char F,char A,char T)
{
    int count=0;
    if(n==1)
    {
       // cout<<"for disk "<<n<<endl;
        cout<<"Move disk from "<<F<<" to "<<T<<endl;
    }
    else
    {
       //cout<<"for disk "<<n<<endl;
        toi(n-1,F,T,A);
        cout<<"Move disk from "<<F<<" to "<<T<<endl;
        toi(n-1,A,F,T);        
    }
    count++;
    cout<<count<<endl;
}
int main()
{
    int n=4;
    char f='F',a='A',t='T';
    toi(n,f,a,t);
}