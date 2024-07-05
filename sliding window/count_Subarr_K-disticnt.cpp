/*
992. Subarrays with K Different Integers
Hard
Given an integer array nums and an integer k, return the number of good subarrays of nums.
A good array is an array where the number of different integers in that array is exactly k.
For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.


Example 1:
Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

Example 2:
Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
*/

#include <bits/stdc++.h>
using namespace std;


int countAtMostK(vector<int>& a,int k){

    unordered_map<int,int> map;
    int i = 0, cnt = 0, n = a.size();
    
    for(int j = 0; j<n; j++){
        map[a[j]]++;

        while(map.size()>k){
            map[a[i]]--;
            if(map[a[i]]==0) map.erase(a[i]);
            i++;
        }
        cnt += j-i+1; 
    }
    return cnt;
}


int subarraysWithKDistinct(vector<int>& a, int k) {
    return countAtMostK(a,k) - countAtMostK(a,k-1);
}