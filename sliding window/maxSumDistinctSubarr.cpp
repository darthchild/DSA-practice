/*
2461. Maximum Sum of Distinct Subarrays With Length K
Medium
You are given an integer array nums and an integer k. Find the maximum subarray 
sum of all the subarrays of nums that meet the following conditions:
    1. The length of the subarray is k
    2. All the elements of the subarray are distinct.
Return the maximum subarray sum of all the subarrays that meet the conditions.4
If no subarray meets the conditions, return 0. A subarray is a contiguous non-empty 
sequence of elements within an array.

 

Example 1:
Input: nums = [1,5,4,2,9,9,9], k = 3
Output: 15

Example 2:
Input: nums = [1,2,4,8,4,1,5], k = 3
Output: 14

Example 3:
Input: nums = [4,4,4], k = 3
Output: 0
Explanation: The subarrays of nums with length 3 are: [4,4,4] 
which does not meet the requirements because the element 4 is repeated.
We return 0 because no subarrays meet the conditions
.*/

#include <bits/stdc++.h>
using namespace std;

long long maximumSubarraySum(vector<int>& a, int k) {
    long long sum = 0, maxSum = 0;
    int i = 0;
    unordered_set<int> s; // to store the current Subarray

    for (int j = 0; j < a.size(); j++) {
        // Shrink window if necessary
        while (s.count(a[j]) || s.size() == k) {
            sum -= a[i];
            s.erase(a[i]);
            i++;
        }

        // Expand window
        sum += a[j];
        s.insert(a[j]);

        // Update maxSum if we have a valid window
        if (s.size() == k) 
            maxSum = max(maxSum, sum);
    }
    return maxSum;
}
