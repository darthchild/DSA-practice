// EXACTLY K DISTICNT 

/*
Longest K unique characters substring (GFG)
Difficulty: Medium
Given a string you need to print the size of the longest possible substring that has
exactly K unique characters. If there is no possible substring then print -1.

Example 1:

Input:
S = "aabacbebebe", K = 3
Output: 
7
Explanation: 
"cbebebe" is the longest substring with 3 distinct characters.
Example 2:

Input: 
S = "aaaa", K = 2
Output: -1
Explanation: 
There's no substring with 2 distinct characters.
*/    

#include <bits/stdc++.h>
using namespace std;
    
int longestKSubstr(string s, int k) {
    
    if(s.empty()) return 0;
    
    int n = s.size(), i=0, maxSize = 0;
    unordered_map<int,int> map;
    
    for(int j = 0; j<n; j++){
        
        map[s[j]]++;
        
        if(map.size() > k){
            map[s[i]]--;
            if(map[s[i]] == 0) map.erase(s[i]);
            i++;
        }
        
        if(map.size() == k)
            maxSize = max(maxSize,j-i+1);
    }
    
    return maxSize = maxSize == 0 ? -1 : maxSize;
}


// AT MOST K DISTINCT 

/*
Longest Substring with At Most K Distinct Characters (Coding Ninja)
Moderate
Problem statement
You are given a string 'str' and an integer ‘K’. Your task is to find the length of the 
largest substring with at most ‘K’ distinct characters.

For example:
You are given ‘str’ = ‘abbbbbbc’ and ‘K’ = 2, then the substrings 
that can be formed are [‘abbbbbb’, ‘bbbbbbc’]. Hence the answer is 7.
*/

int kDistinctChars(int k, string &s){
    
    if(s.empty()) return 0;

    int n = s.size(), i = 0, maxSize = 0;
    unordered_map<int,int> map;

    for(int j = 0; j<n; j++){

        map[s[j]]++;

        if(map.size() > k){
            map[s[i]]--;
            if(map[s[i]] == 0) map.erase(s[i]);
            i++;
        }

        // "at most" K disticnt = "<= K"
        if(map.size() <= k)
            maxSize = max(maxSize,j-i+1);
    }

    return maxSize;
}


