/*
209. Minimum Size Subarray Sum
Medium
Given an array of positive integers nums and a positive integer target,
return the minimal length of a subarray whose sum is greater than or 
equal to target. If there is no such subarray, return 0 instead.

Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:
Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
*/

#include <bits/stdc++.h>
using namespace std;

int smallestSubArrayLen(vector<int>& arr,int target) {
    
    int i = 0, j; // window Start & End pointers
    int sum = 0, minSize = INT_MAX, n = arr.size();

    for(j = 0; j<n; j++){
        
        sum += arr[j];

        while(sum >= target){
            minSize = min(minSize, j-i+1);
            sum -= arr[i];
            i++;
        }
    }

    // if minSize is still INT_MAX 
    // (no such subarray found), j've to return 0

    return minSize == INT_MAX ? 0 : minSize;;
}


int main(){
    vector<int> arr = {4,2,2,7,1,2};
    int target = 8;

    cout << smallestSubArrayLen(arr,target);
}