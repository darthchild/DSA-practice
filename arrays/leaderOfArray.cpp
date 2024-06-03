/*
Leaders in an array (GFG)
Easy 

Given an array A of positive integers. Your task is to find the
leaders in the array. An element of the array is a leader if it 
is greater than all the elements to its right side or if it is 
equal to the maximum element on its right side. The rightmost
element is always a leader. 

A[] = {16,17,4,3,5,2}
Output: 17 5 2

A[] = {10,4,2,4,1}
Output: 10 4 4 1

*/


#include <bits/stdc++.h>
using namespace std;

// Similar to "Replace with Greatest on Right (Leetcode)"
// TRICK: Start iterating from the end of Array

vector<int> leaders(vector<int> arr, int n){
    
    vector<int> res;
    
    // last element will always be the leader
    int max = arr[n-1];
    res.push_back(max);
    
    for(int i=n-2; i>=0; i--){
        
        if(arr[i] >= max){
            max = arr[i];
            res.push_back(max);
        }
    }
    
    reverse(res.begin(), res.end());
    return res;  
}


vector<int> leaders1(vector<int> arr, int n){
    
    vector<int> res;
    int cMax = 0;
    
    for(int i=n-1; i>=0; i--){

        cMax = max(arr[i],cMax);
        if(arr[i] == cMax)
            res.push_back(cMax);
    }
    
    reverse(res.begin(), res.end());
    return res;  
}


int main(){
    vector<int> arr = {16,17,4,3,5,2};
    vector<int> result = leaders1(arr,arr.size());

    for(auto i:result)
        cout << i << " ";
    cout << endl;
}