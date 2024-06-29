/*
Count number of substrings (GFG)
Medium
Given a string of lowercase alphabets, count all possible substrings 
(not necessarily distinct) that have exactly k distinct characters. 

Example 1:
Input: "aba", K = 2
Output:3
Explanation:The substrings are: "ab", "ba" and "aba".

Input: "abaaca", K = 1
Output: 7
Explanation: The substrings are: "a", "b", "a", "aa", "a", "c", "a". 

Your Task:
You don't need to read input or print anything. Your task is to complete the function 
substrCount() which takes the string S and an integer K as inputs and returns the number 
of substrings having exactly K distinct characters.

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).*/


#include <bits/stdc++.h>
using namespace std;


long long int count(const string& s, int k) {
    if (k == 0) return 0;
    
    int n = s.length();
    int i = 0, j = 0;
    long long int count = 0;
    vector<int> freq(26, 0);
    int uniq = 0;
    
    while (j < n) {
        
        // Add the current character to the window
        if (freq[s[j] - 'a'] == 0) uniq++;
        freq[s[j] - 'a']++;
        j++;
        
        // Shrink the window from the left until we have at most k unique characters
        while (uniq > k) {
            if (freq[s[i] - 'a'] == 1) {
                uniq--;
            }
            freq[s[i] - 'a']--;
            i++;
        }
        
        // Add the number of substrings ending at j-1 with at most k unique characters
        count += (j - i);
    }
    
    return count;
}
