/*
560. Subarray Sum Equals K

Given an array of integers nums and an integer k, return the 
total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

 
Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
*/

#include <bits/stdc++.h>
using namespace std;
 
 
int subarraySum(vector<int>& a, int k) {
        
        map<int,int> map;
        map[0] = 1;
        int sum = 0, cnt = 0;

        for(int i=0; i<a.size(); i++){
            sum += a[i];

            int rem = sum-k;
            cnt += map[rem];

            map[sum] += 1;
        }

        return cnt;
    }