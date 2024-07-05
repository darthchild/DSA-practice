/*
1248. Count Number of Nice Subarrays
Medium
Given an array of integers nums and an integer k. A continuous subarray 
is called nice if there are k odd numbers on it. Return the number of nice 
sub-arrays.


Example 1:
Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

Example 2:
Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
*/

#include <bits/stdc++.h>
using namespace std;

int countAtMost(vector<int>& a, int k){

    int n = a.size(), i = 0, odd = 0, cnt = 0;

    for(int j=0; j<n; j++){
        if(a[j] % 2 != 0)
            odd++;
        
        while(odd > k){
            if(a[i] % 2 != 0)
                odd--;
            i++;
        }
        cnt += j - i;
    }
    return cnt;
}


int numberOfSubarrays(vector<int>& a, int k) {
    return countAtMost(a,k) - countAtMost(a,k-1);
}

/*
[1,1,2,1,1] -> 2
3
[2,4,6] -> 0 
1
[2,2,2,1,2,2,1,2,2,2] -> 16
2*/