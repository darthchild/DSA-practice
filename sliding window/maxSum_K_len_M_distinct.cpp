/*
2841. Maximum Sum of Almost Unique Subarray
(Max sum of subarray of length 'k' with 'm' distinct elements)
Medium
You are given an integer array nums and two positive integers
m and k. Return the maximum sum out of all almost unique subarrays 
of length k of nums. If no such subarray exists, return 0.
A subarray of nums is almost unique if it contains at least m distinct elements.

 
Example 1:
Input: nums = [2,6,7,3,1,7], m = 3, k = 4
Output: 18
Explanation: There are 3 almost unique subarrays of size k = 4. 
These subarrays are [2, 6, 7, 3], [6, 7, 3, 1], and [7, 3, 1, 7]. 
Among these subarrays, the one with the maximum sum is [2, 6, 7, 3] which has a sum of 18.

Example 2:
Input: nums = [5,9,9,2,4,5,4], m = 1, k = 3
Output: 23

Example 3:
Input: nums = [1,2,1,2,1,2,1], m = 3, k = 3
Output: 0
*/

#include <bits/stdc++.h>
using namespace std;

long long maxSum(vector<int>& a, int m, int k) {
    long long sum = 0, maxSum = 0;
    int i = 0, n = a.size();
    unordered_map<int, int> map; // Use map to track frequency

    for (int j = 0; j < n; j++) {
        // Add current element to window
        map[a[j]]++;
        sum += a[j];

        // Shrink window if it exceeds size k
        if(j - i + 1 > k) {
            map[a[i]]--;
            if (map[a[i]] == 0) map.erase(a[i]);                
            sum -= a[i];
            i++;
        }
        
        // Check if win size is exactly 'k' & has atleast 'm' distinct elements
        if (j - i + 1 == k && map.size() >= m) 
            maxSum = max(maxSum, sum);
    }
    
    return maxSum;
}


int main(){
    vector<int> arr = {2,6,7,3,1,7};
    int m = 3,k = 4;

    cout << maxSum(arr,m,k);
}


// TEST CASES 
/*
[2,6,7,3,1,7]
3
4
[5,9,9,2,4,5,4]
3
3
[1,2,1,2,1,2,1]
3
3
[1,1,1,3]
2
2
*/
