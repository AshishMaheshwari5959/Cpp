#include <stdlib.h>
#include <iostream>
#include <conio.h>
using namespace std;

int MAXSIZE = 8;
int stack[8];
int top=-1;

bool isempty(){
    if(top==-1)
        return 1;
    else
        return 0;
}

bool isfull(){
    if(top==MAXSIZE)
        return 1;
    else
        return 0;
}

int peek(int index){
    if(index>-1 && index<MAXSIZE){
        return stack[index];
    } else {
        return -1;
    }
}

int pop(){
    int data;
    if(!isempty()){
        data = stack[top];
        top--;
        return data;
    } else {
        return -1;
    }
}

void push(int data){
    if(!isfull()){
        top++;
        stack[top]=data;
    } else {
        cout<<"Stack is full\n";
    }
}

int main()
{
    char temporary;
    push(6);
    push(7);
    push(8);
    push(9);
    int option=0;
    while(option != 5){
        cout<<"Welcome to Stack of Size 8\nPress 1 To print the stack\nPress 2 To push data\nPress 3 To pop data\nPress 4 To peek value\nPress 5 To Exit";
        cout<<"\nEnter Your Option : ";
        cin>>option;
        if(option==1){
            int temp = top;
            while(temp != -1){
                cout<<stack[temp--]<<endl;
            }
            cout<<"Enter any char to continue : ";
            cin>>temporary;
        } else if(option==2){
            int data;
            cout<<"Enter the value you want to push : ";
            cin>>data;
            push(data);
            cout<<"Enter any char to continue : ";
            cin>>temporary;
        } else if(option==3){
            int data = pop();
            cout<<"Popped element is "<<data;
            cout<<"\nEnter any char to continue : ";
            cin>>temporary;
        } else if(option==4){
            int index;
            cout<<"Enter Index where u want to peek : ";
            cin>>index;
            if(index>-1 && index<MAXSIZE){
                cout<<stack[index];
            } else {
                cout<<"Oops you are at invalid index";
            }
            cout<<"\nEnter any char to continue : ";
            cin>>temporary;
        }else if(option!=5){
            cout<<"Enter a correct value";
            cout<<"\nEnter any char to continue : ";
            cin>>temporary;
        }
        system("clear");
    }

    return 0;
}
