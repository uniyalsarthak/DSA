#include<bits/stdc++.h>
using namespace std;

float cylinder(int radius, int height)
{
    float cylinder_volume=3.14*radius*radius*height;
    return cylinder_volume;
}
float top(int radius, int height)
{
    float top_volume=3.14*radius*radius*height;
    return top_volume/2;
}
int main()
{
    float max_volume=INT_MIN;
    int arr[5]={3,7,4,8,1};
    int h1,h2,r;
     for (int i = 0; i < 5; i++)
    {
        for (int j = i+1; j < 5; j++)
        {
            r = (j - i) / 2;
            if (arr[j] < arr[i])
            {
                h1 = arr[j];
                h2 = arr[i] - arr[j];
            }
            else
            {
                h1 = arr[i];
                h2 = arr[j] - arr[i];
            }
            float total_volume=cylinder(r,h1)+top(r,h2);
                if(max_volume<total_volume)
                {
                    max_volume=total_volume;
                }
        }
    }
            cout<<"max volume="<<max_volume<<" cubic units";
}