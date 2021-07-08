#include<iostream>
using namespace std;

void insertion_sort(int *arr,int n){
    for(int i=1; i<n; i++){
        int j = i, temp = arr[i];
        while(temp<arr[j-1] && j>0){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j]=temp;
    }
}

int main(){
    //Insertion sort
    int arr[10]={9,34,25,67,11,60,23,45,99,123};
    cout<<"Array Before Sorting : ";
    for(int i=0; i<10; i++)
        cout<<arr[i]<<" ";
    insertion_sort(arr,10);
    cout<<"\nArray After Sorting : ";
    for(int i=0; i<10; i++)
        cout<<arr[i]<<" ";
    return 0;
}
