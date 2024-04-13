/*
You are given an array 'a' and an integer 'k'.

Find the length of the longest subarray of 'a' whose sum is equal to 'k'.
*/

#include <bits/stdc++.h>
using namespace std;
 
int getLongestSubarray(vector<int>& a, int k) {
    int n = a.size(); // size of the array.

    map<int, int> map;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        //calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        int rem = sum - k;

        //Calculate the length and update maxLen:
        if (map.find(rem) != map.end()) {
            int len = i - map[rem];
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions:
        if (map.find(sum) == map.end()) {
            map[sum] = i;
        }
    }
    return maxLen;
}

int main()
{
    vector<int> a = {2, 3, 5, 1, 9};
    int k = 10;
    int len = getLongestSubarray(a, k);
    cout << len << "\n";
    return 0;
}