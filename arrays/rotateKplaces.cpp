/*
Original Leetcode Question->

189. Rotate Array
(Medium)
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.


Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
*/


#include <bits/stdc++.h>
using namespace std;

void rotateLeft(vector<int> &arr, int k){

    int n = arr.size();
    vector<int> temp;

    for(int i=0; i<k; i++)
        temp.push_back(arr[i]);

    for(int i=0; i<n-k; i++)
        arr[i] = arr[i+k];
    
    for(int i=0; i<k; i++)
        arr[n-k+i] = temp[i];
}


// Optimal in-place solution with O(1) space complexity
void rotateLeftOpt(vector<int> &arr, int k){
    
    reverse(arr.begin(),arr.begin()+k);
    reverse(arr.begin()+k, arr.end());
    reverse(arr.begin(), arr.end());
}

void rotateRight(vector<int> &arr, int k){

    int n = arr.size();
    vector<int> temp;

    for(int i=0; i<k; i++)
        temp.push_back(arr[n-k+i]);

    for(int i=n-k-1; i>=0; i--)
        arr[i+k] = arr[i];

    for(int i=0; i<k; i++)
        arr[i] = temp[i];
}

void rotateRightOpt(vector<int> &A, int k){

    int n = A.size();
    reverse(A.begin(), A.begin()+n-k);
    reverse(A.begin()+n-k, A.end());
    reverse(A.begin(), A.end());
}

void printA(vector<int> A){
    for(int i:A)
        cout << i << " ";
    cout << endl;
}

int main(){

    vector<int> A = {1,2,3,4,5,6,7,8};
    int k = 3;

    // rotateLeft(A,k);
    // printA(A);

    // rotateLeftOpt(A,k);
    // printA(A);

    // rotateRight(A,k);
    // printA(A);

    rotateRightOpt(A,k);
    printA(A);
    

}