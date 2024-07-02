/*
3. Longest Substring Without Repeating Characters=
Medium
Given a string s, find the length of the longest 
substring  without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence 
and not a substring.
*/

#include <bits/stdc++.h>
using namespace std;


int lengthOfLongestSubstring(string s) {
    int size = 0, maxSize = 0, i = 0, n = s.size();
    unordered_map<int,int> map; 

    if(s.empty()) return 0;

    for (int j = 0; j < n; j++) {
        
        // 1. Add elements to window
        size++;
        map[s[j]]++;

        // 2. Shrink window if duplicate elements found
        while (j-i+1 > map.size()) {
            map[s[i]]--;
            if(map[s[i]] == 0) map.erase(s[i]);
            size--;
            i++;
        }

        // 3. Update maxSum
        // (no need for checking for valid window size, since its ensured by above while loop)
        maxSize = max(maxSize, size);
    }
    return maxSize;
}