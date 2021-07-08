#include<iostream>
using namespace std;

void merge_combine(int *arr, int low, int mid, int high){
    int n = high-low+1;
    int arr2[100];
    int i=low,j=mid+1,k=low;
    while(i<mid+1 && j<high+1){
        if(arr[i]<arr[j]){
            arr2[k] = arr[i];
            i++;
            k++;
        } else {
            arr2[k] =arr[j];
            j++;
            k++;
        }
    }
    while(i<mid+1){
        arr2[k] = arr[i];
        i++;
        k++;
    }
    while(j<high+1){
        arr2[k] = arr[j];
        j++;
        k++;
    }
    for(int x=low ; x<high+1; x++){
        arr[x] = arr2[x];
    }
}

void merge_sort(int *arr, int low, int high){
    if(low>=high)
        return;
    int mid = (low+high)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge_combine(arr,low,mid,high);
}


int main(){
    //Merge sort
    int arr[10]={9,34,25,67,11,60,23,45,99,123};
    cout<<"Array Before Sorting : ";
    for(int i=0; i<10; i++)
        cout<<arr[i]<<" ";
    merge_sort(arr,0,9);
    cout<<"\nArray After Sorting : ";
    for(int i=0; i<10; i++)
        cout<<arr[i]<<" ";
    return 0;
}
