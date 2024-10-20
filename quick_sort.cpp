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

void quickSort(int* a,int s,int e)
{
    if(s>=e)
    return;
    int p=partition(a,s,e); 
    quickSort(a,s,p-1);
    quickSort(a,p+1,e);
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
    int size=1000;
        while(size<=20000)
    {
        initialise(arr,size);
        clock_t start,end;
        start=clock();
        //cout<<"start:"<<start<<endl;
        for(int j=0;j<=10;j++)
        {
            quickSort(arr,0,size-1);
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
