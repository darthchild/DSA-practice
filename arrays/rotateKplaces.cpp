#include <bits/stdc++.h>
using namespace std;


void rotateLeft(vector<int> &arr, int k){

    int len = arr.size();
    vector<int> temp;

    for(int i=0; i<k; i++)
        temp.push_back(arr[i]);

    for(int i=0; i<len-k; i++)
        arr[i] = arr[i+k];
    
    for(int i=0; i<k; i++)
        arr[len-k+i] = temp[i];
}

void rotateRight(vector<int> &arr, int k){

}

int main(){

    vector<int> A = {1,2,3,4,5,6,7};
    // {4 , 5, 6, 7, _ , _ , _}
    int k = 5;
    rotateLeft(A,k);

    for(int i:A)
        cout << i << " ";
}