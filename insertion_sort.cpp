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

void initialise(int a[], int size)
{

    // Initialize the array with random values
    for (int i = 0; i < size; i++) {
        a[i] = rand() % 1000 + 1;
    }
}

int main()
{
    ofstream outfile("sort_time.csv");
    outfile<<"Array Size,Time (microseconds)\n";
    int arr[60000];
    int size=50;
        while(size<=40000)
    {
        initialise(arr,size);
        clock_t start,end;
        start=clock();
        //cout<<"start:"<<start<<endl;
        for(int j=0;j<=100;j++)
        {
            insertionSort(arr,size);
        }
        end=clock();
        //cout<<"end:"<<end<<endl;
        double duration=(((double) (end - start)) / CLOCKS_PER_SEC)/1000;
        //cout<<"duration:"<<duration<<endl;
        pair<int ,double>store(size,duration);
        cout<<"("<<store.first<<","<<store.second<<") "<<endl;
        size+=1000;
        outfile<<size<<","<<duration<<"\n";
    }
    outfile.close();
}
