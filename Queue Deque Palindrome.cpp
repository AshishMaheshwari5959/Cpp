#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

char myqueue[100];
int MAXSIZE = 100;
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

void enqueue_r(int data){
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

void enqueue_f(int data){
    if(!isfull()){
        if(front==0)
            front = MAXSIZE;
        myqueue[--front]=data;
        itemCount++;
    } else {
        cout<<"\nQueue is full!";
        getch();
    }
}

char dequeue_f(){
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

char dequeue_r(){
    if(isempty()){
        cout<<"\nQueue is empty!";
        return -1;
    } else {
        int data = myqueue[rear--];
        if(rear==-1)
            rear=MAXSIZE-1;
        itemCount--;
        return data;
    }
}

int main(){
    string str;
    cout<<"Enter the string to check for palindrome : ";
    cin>>str;
    for(int i=0; i<str.length(); i++){
        enqueue_r(str[i]);
    }
    while(true){
        if( !isempty() && myqueue[front]==myqueue[rear]){
            char a = dequeue_f();
            char b = dequeue_r();
            //cout<<a<<" "<<b<<endl;
        } else if(isempty()){
            cout<<"A Palindrome\n";
            return 0;
        } else {
            cout<<"Not a Palindrome\n";
            return 0;
        }
    }
    cout<<"A Palindrome\n";
    return 0;
}
