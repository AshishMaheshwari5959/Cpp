#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;

int MAXSIZE = 8;
int stacks[8];
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
        return stacks[index];
    } else {
        return -1;
    }
}

int pop(){
    int data;
    if(!isempty()){
        data = stacks[top];
        top--;
        return data;
    } else {
        return -1;
    }
}

void push(int data){
    if(!isfull()){
        top++;
        stacks[top]=data;
    } else {
        cout<<"stacks is full\n";
    }
}

int main()
{
    string expression;
    string result="";
    cout<<"Enter the expression : ";
    cin>>expression;
    for(int i=0; i<expression.length(); i++){
        char c=expression[i];
        if(c=='(' || c==')' || c=='{' || c=='}' || c=='[' || c==']'){
            if(c=='(' || c=='{' || c=='['){
                push(c);
            } else if (c==')'){
                if(stacks[top]=='('){
                    pop();
                } else {
                    cout<<"Invalid Expression";
                    return 0;
                }
            } else if (c=='}'){
                if(stacks[top]=='{'){
                    pop();
                } else {
                    cout<<"Invalid Expression";
                    return 0;
                }
            } else if (c==']'){
                if(stacks[top]=='['){
                    pop();
                } else {
                    cout<<"Invalid Expression";
                    return 0;
                }
            }
        }
    }
    if(isempty())
        cout<<"Valid Expression";
    else 
        cout<<"Invalid Expression";
    return 0;
}
