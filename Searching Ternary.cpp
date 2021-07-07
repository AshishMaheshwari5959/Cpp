#include<iostream>
using namespace std;
int main(){
    //ternary Search
    //Array must be sorted
    int arr[10]={9,11,23,25,34,45,60,67,99,123};
    cout<<"Array in which we are searching : ";
    for(int i=0; i<10; i++)
        cout<<arr[i]<<" ";
    int value;
    cout<<"\nEnter the value you want to search for : ";
    cin>>value;
    int found=0,index;
    int low=0,high=9,mid1,mid2;
    while(low<=high){
        mid1 =low + (high-low)/3;
        mid2 = high - (high-low)/3;
        if(arr[mid1]==value){
            found=1;
            index = mid1+1;
            break;
        } else if(arr[mid2]==value){
            found=1;
            index = mid2+1;
            break;
        } else if(arr[mid1]>value){
            high = mid1-1;
        } else if(arr[mid2]<value){
            low = mid2+1;
        } else {
            low = mid1+1;
            high = mid2-1;
        }
    }
    if(found==1)
    cout<<"Value "<<value<<" is found at position "<<index;
    else
    cout<<"Not found";
    return 0;
}
