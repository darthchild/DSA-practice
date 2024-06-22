/*
3190. Find Minimum Operations to Make All Elements Divisible by Three
Easy
You are given an integer array nums. In one operation, you can add or 
subtract 1 from any element of nums.Return the minimum number of operations
to make all elements of nums divisible by 3.

Example 1:
Input: nums = [1,2,3,4]
Output: 3
Explanation: All array elements can be made divisible by 3 using 3 operations:
Subtract 1 from 1.
Add 1 to 2.
Subtract 1 from 4.

Example 2:
Input: nums = [3,6,9]
Output: 0
*/

#include <bits/stdc++.h>
using namespace std;

int minimumOperations(vector<int>& a) {

    int n = a.size();
    int cnt = 0;

    for(int i=0; i<n; i++){

        if(a[i]%3 != 0){
            if( (a[i]+1)%3 == 0)
                cnt++;
            else if( (a[i]-1)%3 == 0)
                cnt++;
        }
    }

    return cnt;

}