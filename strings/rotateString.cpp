/*
796. Rotate String
Given two strings s and goal, return true if and only if s can 
become goal after some number of shifts on s. A shift on s consists
of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
 
Example 1:
Input: s = "abcde", goal = "cdeab"
Output: true

Example 2:
Input: s = "abcde", goal = "abced"
Output: false
*/

#include <bits/stdc++.h>
using namespace std;

string rotate(string s,int k){
    int n = s.size();

    reverse(s.begin(), s.end()-k);
    reverse(s.begin()+n-k, s.end());
    reverse(s.begin(),s.end());
    return s;
}

bool rotateString(string s, string goal) {
    
    if(s.size() != goal.size()) return false;
    if(s == goal) return true;

    int n = s.size();

    for(int i = 1; i<n; i++){
        if(rotate(s,i) == goal)
            return true;
    }
    return false;
}
