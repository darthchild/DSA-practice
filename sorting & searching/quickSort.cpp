// Quick Sort algorithm

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int start, int end){

    int pvt = arr[start];
    int i = start+1, j = end;

    while(i < j){
        while(arr[i] < pvt && i < arr.size())
            i++;
        while(arr[j] >= pvt)
            j--;
        if(i < j)
            swap(arr[i],arr[j]);
    }
    //when j has crossed i 
    swap(arr[start],arr[j]); // now pivot element is in its sorted position
    return j; //returns pivot element's index
}

void quickSort(vector<int> &arr, int start, int end){
    if(start < end){
        int pvt = partition(arr,start,end);
        quickSort(arr,start,pvt-1);
        quickSort(arr,pvt+1,end);
    }
}

int main(){

    vector<int> arr = {2,0,1};
    quickSort(arr,0,arr.size()-1);

    for(int i: arr)
        cout << i << " ";
}