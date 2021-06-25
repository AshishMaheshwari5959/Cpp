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
    string expression;
    string result="";
    cout<<"Enter the expression : ";
    cin>>expression;
    for(int i=0; i<expression.length(); i++){
        char c = expression[i];
        if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='(' || c==')'){
            if(isempty()){
                push(c);
            } else{
                if(c=='('){
                    push(c);
                } else if(c==')'){
                    while(stack[top]!='('){
                        char data;
                        data = pop();
                        result += data;
                    }
                    char data = pop();
                } else if(c=='+' || c=='-'){
                    if(stack[top]=='('){
                        push(c);
                    } else{
                        while(!isempty()){
                            if(stack[top]!='('){
                                char data;
                                data = pop();
                                result += data;
                            } else {
                                break;
                            }
                        }
                        push(c);
                    }
                } else if(c=='*' || c=='/'){
                    if(stack[top]=='+' || stack[top]=='-' || stack[top]=='(' ){
                        push(c);
                    } else {
                        while(!isempty()){
                            if(stack[top]!='(' && stack[top]!='+' && stack[top]!='-'){
                                char data;
                                data = pop();
                                result += data;
                            } else {
                                break;
                            }
                        }
                        push(c);
                    }
                } else if(c=='^'){
                    if(stack[top]=='+' || stack[top]=='-' || stack[top]=='*' || stack[top]=='*' || stack[top]=='(' ){
                        push(c);
                    } else {
                        while(!isempty()){
                            if(stack[top]!='(' && stack[top]!='+' && stack[top]!='-' && stack[top]!='*' && stack[top]!='/'){
                                char data;
                                data = pop();
                                result += data;
                            } else {
                                break;
                            }
                        }
                        push(c);
                    }
                }
            }
        } else {
            result += c;
        }
    }
    while(!isempty()){
        char data;
        data=pop();
        result += data;
    }
    cout<<result;
    return 0;
}
