/*
128. Longest Consecutive Sequence
Medium
Given an unsorted array of integers nums, return the length
of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:
    Input: nums = [100,4,200,1,3,2]
    Output: 4
    Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
    Therefore its length is 4.

Example 2:
    Input: nums = [0,3,7,2,5,8,4,6,0,1]
    Output: 9
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Soln
// TC - O(nlogn), SC - O(1)
int longestConsecutive(vector<int>& a) {
    int n = a.size(), maxLen = 0;

    for(int i=0; i<n; i++){
        int find = a[i]+1, j = 0;
        int cnt = 1;

        while(j < n){
            if(a[j] == find){
                cnt++;
                find++;
                j = 0;
            } else 
                j++;
            
            if(j == n-1 && a[j] != find)
                break;
        }
        
        maxLen = max(maxLen,cnt);
    }   
    return maxLen;
}


// Optimal Solution 
// TC - O(n), worst case - O(nlogn)
// SC - O(n)

int longestConsecutive1(vector<int>& a) {
        
    int n = a.size(),longest = 1;
    unordered_set<int> st;

    if(n == 0) return 0;

    //putting E in set
    for(int i=0; i<n; i++){
        st.insert(a[i]);
    }

    // iterating set to finding longest Seq.
    for(auto it:st){

        // if curr-1 is not present in arr -> this is 1st Num of Seq.
        if(st.find(it-1) == st.end()){
            int cnt = 1;
            while(st.find(it+1) != st.end()){
                it++;
                cnt++;
            }
            longest = max(longest,cnt);
        }
    }

    return longest;
}

int main(){
    vector<int> arr = {100,4,200,1,3,2};
    cout << longestConsecutive(arr);
}