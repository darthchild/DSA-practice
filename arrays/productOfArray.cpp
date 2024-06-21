/*
238. Product of Array Except Self
Medium
Given an integer array nums, return an array answer such that answer[i]
is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in 
a 32-bit integer.You must write an algorithm that runs in O(n) time 
and without using the division operation.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
*/

#include <bits/stdc++.h>
using namespace std;

/* APPROACH: 
For every element a[i] in array a, we'll first calculate the prod of all elements 
right of it -> store this in a arr, then calculate the prod of all elements left of 
it -> store this in another array, now just multiply the elements in corresponding
indexes to get the array product without a[i] 
*/ 

vector<int> productExceptSelf(vector<int>& a) {
        
    int n = a.size();
    vector<int> left, right, res;

    int prod = 1;
    left.push_back(prod);

    for(int i=1; i<n; i++){
        prod *= a[i-1];
        left.push_back(prod);
    }

    prod = 1;
    right.push_back(prod);

    for(int i=n-2; i>=0; i--){
        prod *= a[i+1];
        right.push_back(prod);
    }
    reverse(right.begin(),right.end());
    
    for(int i=0; i<n; i++)
        res.push_back(left[i]*right[i]);

    return res;

}