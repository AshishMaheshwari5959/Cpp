#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

int myqueue[8];
int MAXSIZE = 8;
int front = -1;
int rear = -1;

bool isempty(){
    if(front==-1 && rear==-1)
        return 1;
    else
        return 0;
}

bool isfull(){
    if(rear==(MAXSIZE-1))
        return 1;
    else
        return 0;
}

int peek(){
    if(!isempty())
        return myqueue[front];
    return -1;
}

void enqueue(int data){
    if(isempty()){
        front++;
        rear++;
        myqueue[rear]=data;
    } else if(!isfull()){
        rear++;
        myqueue[rear]=data;
    } else {
        cout<<"\nQueue is full!";
    }
}

int dequeue(){
    if(isempty()){
        cout<<"\nQueue is empty!";
        return 0;
    } else {
        int data = myqueue[front];
        front++;
        return data;
    }
}

int main(){
    int option=0;
    while(option!=5){
        cout<<"Welcome to queue of size 8\nPress 1 To print queue\nPress 2 To insert in queue\nPress 3 To peek\nPress 4 To delete from queue\nPress 5 To exit";
        cout<<"\nEnter your option : ";
        cin>>option;
        if(option==1){
            if(isempty()){
                cout<<"Queue is Empty\n";
            } else {
                for(int i=front; i<=rear; i++){
                    cout<<myqueue[i]<<endl;
                }
            }
            char ch;
            cout<<"\nEnter any key to continue ";
            cin>>ch;
        } else if(option==2){
            int data;
            cout<<"Enter the value to insert : ";
            cin>>data;
            enqueue(data);
            char ch;             
            cout<<"\nEnter any key to continue ";             
            cin>>ch;;
        } else if(option==3){
            cout<<"The value at the front is : "<<peek()<<endl;
            char ch;             
            cout<<"\nEnter any key to continue ";             
            cin>>ch;;
        } else if(option==4){
            int data;
            data = dequeue();
            cout<<"Value deleted from queue is "<<data<<endl;
            char ch;             
            cout<<"\nEnter any key to continue ";             
            cin>>ch;;
        } else if(option==5){
            cout<<"Bye Bye";
            return 0;
        } else {
            cout<<"Enter value correctly"<<endl;
        }
        system("clear");
    }
    return 0;
}
