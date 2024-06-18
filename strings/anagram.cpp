/*
242. Valid Anagram
Given two strings s and t, return true if t is an anagram of s, 
and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters
of a different word or phrase, typically using all the original
letters exactly once.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false
*/

#include <bits/stdc++.h>
using namespace std;


bool isAnagram(string s1, string s2) {
    
    unordered_map<char,int> map;

    for(auto& c:s1)
        map[c]++;

    for(auto& c:s2)
        map[c]--;

    for(auto& p:map){
        if(p.second != 0)
            return false;
    }
    return true;
    
}

bool isAnagram(string s1, string s2) {
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    return s1 == s2;
}