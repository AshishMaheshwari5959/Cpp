#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

int myqueue[8];
int MAXSIZE = 8;
int front = 0;
int rear = -1;
int itemCount = 0;

bool isempty() {
   return itemCount == 0;
}

bool isfull() {
   return itemCount == MAXSIZE;
}

int peek(){
    if(!isempty())
        return myqueue[front];
    return -1;
}

void enqueue(int data){
    if(!isfull()){
        if(rear==MAXSIZE-1)
            rear=-1;
        myqueue[++rear]=data;
        itemCount++;
    } else {
        cout<<"\nQueue is full!";
        getch();
    }
}

int dequeue(){
    if(isempty()){
        cout<<"\nQueue is empty!";
        return -1;
    } else {
        int data = myqueue[front++];
        if(front==MAXSIZE)
            front=0;
        itemCount--;
        return data;
    }
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    int option=0;
    while(option!=5){
        cout<<"Welcome to queue of size 8\nPress 1 To print queue\nPress 2 To insert in queue\nPress 3 To peek\nPress 4 To delete from queue\nPress 5 To exit";
        cout<<"\nEnter your option : ";
        cin>>option;
        if(option==1){
            if(isempty()){
                cout<<"Queue is Empty\n";
            } else {
                if(front<=rear)
                    for(int i=front; i<=rear; i++)
                        cout<<i<<" "<<myqueue[i]<<endl;
                else{
                    for(int i=front; i<=MAXSIZE-1; i++)
                        cout<<i<<" "<<myqueue[i]<<endl;
                    for(int i=0; i<=rear; i++)
                        cout<<i<<" "<<myqueue[i]<<endl;
                }
            }
            getch();
        } else if(option==2){
            int data;
            cout<<"Enter the value to insert : ";
            cin>>data;
            enqueue(data);
        } else if(option==3){
            if(peek()!=-1)
                cout<<"The value at the front is : "<<peek()<<endl;
            else
                cout<<"Queue is empty";
            getch();
        } else if(option==4){
            int data;
            data = dequeue();
            if(data!=-1)
                cout<<"Value deleted from queue is "<<data<<endl;
            getch();
        } else if(option==5){
            cout<<"Bye Bye";
            return 0;
        } else {
            cout<<"Enter value correctly"<<endl;
        }
        system("cls");
    }
    return 0;
}
