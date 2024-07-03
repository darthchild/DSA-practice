/*
2958. Length of Longest Subarray With at Most K Frequency
Medium
You are given an integer array nums and an integer k.
The frequency of an element x is the number of times it occurs in an array.
An array is called good if the frequency of each element in this array is less than or equal to k.
Return the length of the longest good subarray of nums.

Example 1:
Input: nums = [1,2,3,1,2,3,1,2], k = 2
Output: 6
Explanation: The longest possible good subarray is [1,2,3,1,2,3] since the values 1, 2, and 3 occur at most twice in this subarray. Note that the subarrays [2,3,1,2,3,1] and [3,1,2,3,1,2] are also good.
It can be shown that there are no good subarrays with length more than 6.

Example 2:
Input: nums = [2,3,3,4,5], k = 1
Output: 3
Explanation: The longest such subarray will be [3,4,5]
*/

#include <bits/stdc++.h>
using namespace std;

int maxSubarrayLength(vector<int>& a, int k) {
        
    int n = a.size(), i = 0, maxLen = -1;
    unordered_map<int,int> map;

    for(int j=0; j<n; j++){
        map[a[j]]++;

        while(map[a[j]] > k){
            map[a[i]]--;
            i++;
        }

        maxLen = max(maxLen,j-i+1);
    }
    return maxLen;
}

// ALT WAY TO WRITE (Same code)
int maxSubarrayLength(vector<int>& a, int k) {
    
    int n = a.size(), i = 0, maxLen = -1;
    unordered_map<int,int> map;

    for(int j=0; j<n; j++){
        map[a[j]]++;

        if(map[a[j]] <= k){
            maxLen = max(maxLen,j-i+1);
        } else {
            // Shrink 
            while(map[a[j]] > k){
                map[a[i]]--;
                i++;
            }
        }
    }

    return maxLen;
}