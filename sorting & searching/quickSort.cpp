// Quick Sort 

#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &arr, int start, int end){

    int pivot = arr[start];
    int i = start;
    int j = end;

    while(i < j){
        while(arr[i] <= pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if(i < j)
            swap(arr[i],arr[j]);
    }
    //when j has crossed i 
    swap(arr[start],arr[j]); // now pvt element is in its sorted position
    return j; //returns pivot element's index
}

void quickSort(vector<int> &arr, int start, int end){
    if(start < end){
        int pivot = partition(arr,start,end);
        quickSort(arr,start,pivot-1);
        quickSort(arr,pivot+1,end);
    }
}

int main(){

    vector<int> arr = {6,5,9,1,4,8};
    quickSort(arr,0,5);

    for(int i: arr){
        cout << i << " ";
    }
}