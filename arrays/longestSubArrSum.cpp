/*
You are given an array 'a' and an integer 'k'.

Find the length of the longest subarray of 'a' whose sum is equal to 'k'.
*/

#include <bits/stdc++.h>
using namespace std;
 

// BETTER SOLUTION
int longestSubarr(vector<int> &arr, int k){

    map<int,int> Map;
    int maxlen = 0;
    int len = 0;
    int sum = 0; // sum till current Index (currSum)

    for(int i=0; i<arr.size(); i++){
        sum += arr[i];

        // if sum not mapped yet
        if(Map.find(sum) == Map.end())
            Map[sum] = i;

        // calculate the sum of remaining part (currSum-k)
        int rem = sum - k;
        // if we find Rem Sum in the map
        if(Map.find(rem) != Map.end())
            len = i - Map[rem];
            maxlen = max(maxlen,len);

        // if reqd Subarr starts from 0, then currSum will be = k
        if(sum == k)
            maxlen = max(maxlen,i+1);
    }
    return maxlen;
}



// OPTIMAL SOLUTION
int getLongestSubarray(vector<int>& arr, int k) {
    int start = 0, end = 0, maxlen = 0;
    int sum = arr[0];
    int n = arr.size();
    
    while(end < n){
        
        // CASE sum > k
        while(sum > k && start <= end){
            sum -= arr[start];
            start++;
        }

        // CASE sum = k
        if(sum == k){
            int len = end-start+1;
            maxlen = max(len,maxlen);
        }

        //CASE sum < k
        end++;
        if(end < n)
            sum += arr[end];
    }
    return maxlen;
}


int main()
{
    vector<int> a = {9, 1, 1, 3, 5, 1, 9};
    int k = 10;
    int len = getLongestSubarray2(a, k);
    cout << "max length with sum k : " << len << "\n";
    return 0;
}