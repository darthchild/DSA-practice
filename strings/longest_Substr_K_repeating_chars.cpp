/*
395. Longest Substring with At Least K Repeating Characters
Medium
Given a string s and an integer k, return the length of the longest substring of s such
that the frequency of each character in this substring is greater than or equal to k.
if no such substring exists, return 0.

Example 1:
Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.

Example 2:
Input: s = "bbaaacbd", k = 3
Output: 3
Explanation: The longest substring is "aaa"
*/

#include <bits/stdc++.h>
using namespace std;


int longestSubstring(string s, int k) {
    
    int i = 0, n = s.size(), l1,l2; // for  length of the 2 substrings 
    unordered_map<int,int> map;
    if(n == 0 || n < k) return 0;
    if(k <= 1) return n;

    // 0. mapping the string's chars
    for(char c:s)
        map[c]++;

    // Step 1: Finding BP
    while(i<n && map[s[i]] >= k)
        i++;
    //  check if BP is last E or no BP 
    if(i >= n-1)
        return i;

    // Step 2: Rec fn call on substring left of BP 
    l1 = longestSubstring(s.substr(0,i),k);

    // Step 3: Looking for multiple BPs together
    while(i < n && map[s[i]] < k)
        i++;

    // Step 4. RFC on substring right of BP (IF CHARS ARE LEFT)
    if(i < n)
        l2 = longestSubstring(s.substr(i),k);
    else 
        l2 = 0;

    // Step 5: Return the bigger answer
    return max(l1,l2);
}