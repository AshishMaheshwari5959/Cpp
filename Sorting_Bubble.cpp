#include<iostream>
using namespace std;
void bubble_sort(int *arr,int n){
    for(int i=0; i<n-1 ; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    //Binary sort
    int arr[10]={9,34,25,67,11,60,23,45,99,1};
    cout<<"Array Before Sorting : ";
    for(int i=0; i<10; i++)
        cout<<arr[i]<<" ";
    bubble_sort(arr,10);
    cout<<"\nArray After Sorting : ";
    for(int i=0; i<10; i++)
        cout<<arr[i]<<" ";
    return 0;
}
