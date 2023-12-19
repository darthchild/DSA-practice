/*
215. Kth Largest Element in an Array

Given an integer array nums and an integer k, return the kth largest 
element in the array.
*/

#include <bits/stdc++.h>

using namespace std;

int quickSelect(vector<int>& nums, int k) {
    int pivot = nums[rand() % nums.size()];
    
    vector<int> left;
    vector<int> mid;
    vector<int> right;
    
    for (int num: nums) {
        if (num > pivot) {
            left.push_back(num);
        } else if (num < pivot) {
            right.push_back(num);
        } else {
            mid.push_back(num);
        }
    }
    
    if (k <= left.size()) {
        return quickSelect(left, k);
    }
    
    if (k > left.size() + mid.size() ) {
        return quickSelect(right, k - left.size() - mid.size());
    }
    
    return pivot;
    
}

void main(){

    vector<int> arr = {3,5,2,1,6,4};
    int k = 2;
    quickSelect(arr,k);
}
