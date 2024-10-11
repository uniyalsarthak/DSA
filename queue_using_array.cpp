#include<bits/stdc++.h>
using namespace std;
int arr[100];
int front=-1;
int rear=-1;
void enqueue(int a)
{
    if(front==-1 && rear==-1)                 //check array is empty
    {
        front++;
        rear++;
        arr[rear]=a;
    }
    else
    {
        rear++;
        arr[rear]=a;
    }
}
void print()
{
    if (front == -1) {
        cout << "Queue is empty!" << endl;
        return;
    }
    for (int i = front; i <= rear; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << "Dequeued: " << arr[front] << endl;            
    front++;                                                         //dequeue the element
    
    if (front > rear) {                 
        front = -1;
        rear = -1;
    }
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    dequeue();
    print();

    
}