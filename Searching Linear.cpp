#include<iostream>
using namespace std;
int main(){
    //Linear Search
    int arr[10]={9,34,25,67,11,60,23,45,99,123};
    cout<<"Array in which we are searching : ";
    for(int i=0; i<10; i++)
        cout<<arr[i]<<" ";
    int value;
    cout<<"\nEnter the value you want to search for : ";
    cin>>value;
    int found=0,index;
    for(int i=0; i<10; i++){
        if(arr[i]==value){
            found=1;
            index = i+1;
            break;
        }
    }
    if(found==1)
    cout<<"Value "<<value<<" is found at position "<<index;
    else
    cout<<"Not found";
    return 0;
}
