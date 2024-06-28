/*
2461. Maximum Sum of Distinct Subarrays With Length K
Medium
You are given an integer array nums and an integer k. Find the maximum subarray 
sum of all the subarrays of nums that meet the following conditions:
    1. The length of the subarray is k
    2. All the elements of the subarray are distinct.
Return the maximum subarray sum of all the subarrays that meet the conditions.
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


// Dynamic Length SW (using Set)
long long maximumSubarraySum1(vector<int>& a, int k) {
    long long sum = 0, maxSum = 0;
    int i = 0;
    unordered_set<int> s; // to store the current Subarray

    for (int j = 0; j < a.size(); j++) {

        // 1. Expand window
        sum += a[j];

        // 2. Shrink window if necessary
        while ( s.size() >= k || s.count(a[j]) ) {
            sum -= a[i];
            s.erase(a[i]);
            i++;
        }

        // 3. Add it to set (make it part of curr subarray)
        s.insert(a[j]);

        // 4. Update maxSum if we have a valid window
        if (s.size() == k) 
            maxSum = max(maxSum, sum);
    }
    return maxSum;
}


// Fixed Length SW (using Map)
long long maximumSubarraySum2(vector<int>& a, int k) {

    long long maxSize = 0, sum = 0;
    unordered_map<int, int> map;
    int i = 0;

    while(i < k  && i < a.size()){ // store first k elements in the map
        map[a[i]]++;
        sum += a[i];
        i++;
    }
    cout << "i: "<<i << endl;
    
    if(map.size() == k) maxSize = sum; // if all distinct, then ans = sum 
    
    while(i < a.size()){
        map[a[i]]++;
        sum += a[i];

        map[a[i-k]]--;
        sum -= a[i-k];

        if(map[a[i-k]] == 0) 
            map.erase(a[i-k]);       
                    
        if(map.size() == k) 
            maxSize = max(maxSize, sum);
        i++;
    }
    return maxSize;
}


// Dynamic Length SW (using Map)
long long maximumSubarraySum3(vector<int>& a, int k) {

    long long sum = 0, maxSum = 0;
    int i = 0;
    unordered_map<int,int> map; 

    for (int j = 0; j < a.size(); j++) {
        // 1. Shrink window if necessary
        while ( map.size() >= k || map[a[j]] == 1 ) {
            sum -= a[i];
            map[a[i]]--;
            if(map[a[i]] == 0) map.erase(a[i]);
            i++;
        }

        // 2. Expand window
        sum += a[j];
        map[a[j]]++;

        // 3. Update maxSum if we have a valid window
        if (map.size() == k) 
            maxSum = max(maxSum, sum);
    }
    return maxSum;
}


int main(){
    vector<int> arr = {1,5,4,2,9,9,9};
    int k = 3;

    cout << maximumSubarraySum2(arr,k);
}

// TEST CASES 
/*
[1,5,4,2,9,9,9]
3
[4,4,4]
3
[1,7,7,3,4,1]
3
[1,2,4,8,4,1,5]
3
*/
