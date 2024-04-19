/*

53. Maximum Subarray

Given an integer array nums, find the 
subarray with the largest sum, and return its sum.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

*/

#include <bits/stdc++.h>
using namespace std;

int kadaneAlgo(vector<int> arr){
    int sum = 0;
    int max = INT_MIN;

    for(int i=0; i<arr.size(); i++){
        sum += arr[i];

        if(sum > max) 
            max = sum;

        if(sum < 0)
            sum = 0; // Neglect negative sum, reset to 0
    }
    return max;
}

int kadaneGiveSubarray(vector<int> arr){

    // starting & ending index of our answer subarray
    int begin;
    int start = -1, end = -1;
    int sum = 0, max = INT_MIN;

    for(int i=0; i<arr.size(); i++){
        
        if(sum == 0) begin = i; // this'll be the start ind of our new SA

        sum+= arr[i];

        if(sum > max){
            max = sum;
            start = begin, end = i;
        }

        if(sum < 0)
            sum = 0;
    }

    // Printing the answer Subarray
    for(int i=start; i<=end; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    return max;
}


int main(){
    vector<int> arr = {-2,-3,4,-1,-2,1,5,-3};
    
    //cout << "max sum : " << kadaneAlgo(arr);

    cout << "max sum : " << kadaneGiveSubarray(arr);

}