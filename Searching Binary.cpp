#include<iostream>
using namespace std;
int main(){
    //Binary Search
    //Array must be sorted
    int arr[10]={9,11,23,25,34,45,60,67,99,123};
    cout<<"Array in which we are searching : ";
    for(int i=0; i<10; i++)
        cout<<arr[i]<<" ";
    int value;
    cout<<"\nEnter the value you want to search for : ";
    cin>>value;
    int found=0,index;
    int low=0,high=9,mid;
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid]==value){
            found=1;
            index = mid+1;
            break;
        } else if(arr[mid]>value){
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    if(found==1)
    cout<<"Value "<<value<<" is found at position "<<index;
    else
    cout<<"Not found";
    return 0;
}
