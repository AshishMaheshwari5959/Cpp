#include<iostream>
using namespace std;

void selection_sort(int *arr,int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                int temp =arr[j];
                arr[j]=arr[i];
                arr[i] = temp;
            }
        }
    }
}

int main(){
    //Merge sort
    int arr[10]={9,34,25,67,11,60,23,45,99,123};
    cout<<"Array Before Sorting : ";
    for(int i=0; i<10; i++)
        cout<<arr[i]<<" ";
    selection_sort(arr,10);
    cout<<"\nArray After Sorting : ";
    for(int i=0; i<10; i++)
        cout<<arr[i]<<" ";
    return 0;
}
