/*
560. Subarray Sum Equals K

Given an array of integers nums and an integer k, return the 
total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

 
Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
*/

/*
LOGIC: 
if there exists 'n' occurences of a 
prefixSum = currSum - k, then there must exist 'n' occurences 
of prefixSum = k also 
(meaning there must exist 'n' subarrays with sum = k also, till now)

-> current sum : prefix sum of current element
*/

#include <bits/stdc++.h>
using namespace std;
 
 
int subarraySum(vector<int>& a, int k) {
        
    unordered_map<int,int> map;
    map[0] = 1;
    int currSum = 0, cnt = 0, n = a.size();

    for(int i=0; i<n; i++){
        currSum += a[i];

        int rem = currSum-k;
        cnt += map[rem];

        map[currSum]++;
    }

    return cnt;
}