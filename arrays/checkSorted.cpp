/*
Problem statement
You have been given an array ‘a’ of ‘n’ non-negative integers.You have
to check whether the given array is sorted in the non-decreasing order
or not.

Your task is to return 1 if the given array is sorted. Else, return 0.

Example :
Input: ‘n’ = 5, ‘a’ = [1, 2, 3, 4, 5]
Output: 1
*/

#include <bits/stdc++.h>
using namespace std;


int isSorted(int n, vector<int> a) {
    
    // FIRST SOLUTION
    // int cnt = 0;
    // for(int i=0; i<n-1; i++){
    //     if(a[i] <= a[i+1]){
    //         cnt++;
    //     }else{
    //         return 0;
    //     }
    // }

    // if(cnt = n-1)
    //     return 1;

    // BETTER SOLUTION (SELF)
    int i = 0;
    while(a[i] <= a[i+1] && i<n-1) {
        i++;
    }

    if(i == n-1)
        return 1;
    return 0;
}

int main(){
    //vector<int> arr = {1,2,3,4,5};
    vector<int> arr = {2,1};
    cout << isSorted(arr.size(),arr) << endl;
}