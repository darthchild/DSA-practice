/*
1588. Sum of All Odd Length Subarrays
Easy
Given an array of positive integers arr, return the sum of all 
possible odd-length subarrays of arr.
A subarray is a * contiguous * subsequence of the array.

Example 1:

Input: arr = [1,4,2,5,3]
Output: 58
Explanation: The odd-length subarrays of arr and their sums are:
[1] = 1, [4] = 4, [2] = 2, [5] = 5, [3] = 3[1,4,2] = 7, [4,2,5] = 11
[2,5,3] = 10, [1,4,2,5,3] = 15
If we add all these together we get
1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
*/

#include <bits/stdc++.h>
using namespace std;

int sumOddLengthSubarrays(vector<int>& a) {
    
    int sum = 0, odd;
    int n = a.size();

    for (int i = 0; i < n; i++) {
        // total no. of subarrays for a[i]
        int num = (i+1) * (n-i);

        if(num%2 == 0)
            odd = num/2; // no. of odd subarrays
        else 
            odd = num/2 +1; 

        sum += odd * a[i];         
    }
    return sum;
}

// OR

int sumOddLengthSubarrays(vector<int>& a) {
    
    int sum = 0, n = a.size(), contr;

    for (int i = 0; i < n; i++) {
        int num = (i+1) * (n-i); // total no. of subarrays that can be formed by a[i]
        contr = (num/2 + 1)* a[i]; // contr to total SUM by odd SAs of a[i]
        sum += contr;         
    }
    return sum;
}