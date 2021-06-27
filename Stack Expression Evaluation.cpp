#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <conio.h>
#include <stack>
using namespace std;

void evaluate(stack<int> &myoperand, stack<int> &myoperator){
    char data;
    data = myoperator.top();
    myoperator.pop();
    if(data=='+'){
        int r;
        int a,b;
        a = myoperand.top();
        myoperand.pop();
        b = myoperand.top();
        myoperand.pop();
        r = a+b;
        myoperand.push(r);
    } else if(data=='-'){
        int r;
        int a,b;
        a = myoperand.top();
        myoperand.pop();
        b = myoperand.top();
        myoperand.pop();
        r = b-a;
        myoperand.push(r);
    } else if(data=='*'){
        int r;
        int a,b;
        a = myoperand.top();
        myoperand.pop();
        b = myoperand.top();
        myoperand.pop();
        r = a*b;
        myoperand.push(r);
    } else if(data=='/'){
        int r;
        int a,b;
        a = myoperand.top();
        myoperand.pop();
        b = myoperand.top();
        myoperand.pop();
        r = b/a;
        myoperand.push(r);
    } else if(data=='^'){
        int r;
        int a,b;
        a = myoperand.top();
        myoperand.pop();
        b = myoperand.top();
        myoperand.pop();
        r = (int)pow(b,a);
        myoperand.push(r);
    }
}

int main()
{
    stack<int> myoperator;
    stack<int> myoperand;
    string expression,result="";
    cout<<"Enter the expression : ";
    cin>>expression;
    for(int i=0; i<expression.length(); i++){
        char c = expression[i];
        if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='(' || c==')'){
            if(myoperator.empty()){
                myoperator.push(c);
            } else{
                if(c=='('){
                    myoperator.push(c);
                } else if(c==')'){
                    while(myoperator.top()!='('){
                        evaluate(myoperand,myoperator);
                    }
                    myoperator.pop();
                } else if(c=='+' || c=='-'){
                    if(myoperator.top()=='('){
                        myoperator.push(c);
                    } else{
                        while(!myoperator.empty()){
                            if(myoperator.top()!='('){
                                evaluate(myoperand,myoperator);
                            } else {
                                break;
                            }
                        }
                        myoperator.push(c);
                    }
                } else if(c=='*' || c=='/'){
                    if(myoperator.top()=='+' || myoperator.top()=='-' || myoperator.top()=='(' ){
                        myoperator.push(c);
                    } else {
                        while(!myoperator.empty()){
                            if(myoperator.top()!='(' && myoperator.top()!='+' && myoperator.top()!='-'){
                                evaluate(myoperand,myoperator);
                            } else {
                                break;
                            }
                        }
                        myoperator.push(c);
                    }
                } else if(c=='^'){
                    if(myoperator.top()=='+' || myoperator.top()=='-' || myoperator.top()=='*' || myoperator.top()=='*' || myoperator.top()=='(' ){
                        myoperator.push(c);
                    } else {
                        while(!myoperator.empty()){
                            if(myoperator.top()!='(' && myoperator.top()!='+' && myoperator.top()!='-' && myoperator.top()!='*' && myoperator.top()!='/'){
                                evaluate(myoperand,myoperator);
                            } else {
                                break;
                            }
                        }
                        myoperator.push(c);
                    }
                }
            }
        } else {
            myoperand.push((int)c-48);
        }
    }
    while(!myoperator.empty()){
        evaluate(myoperand,myoperator);
    }
    cout<<myoperand.top();
    return 0;
}
