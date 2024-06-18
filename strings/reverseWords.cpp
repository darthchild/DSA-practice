/*
151. Reverse Words in a String
Medium
Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words
in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces 
between two words. The returned string should only have a single space
separating the words. Do not include any extra spaces.

 

Example 1:
Input: s = "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single
space in the reversed string.
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force - O(n) space
string reverseWords(string s) {
    string res, x;
    int n = s.size();

    for (int i = n-1; i >= 0; i--) {
        if (isalnum(s[i])) 
        {
            x = s[i] + x; 
        } 
        else if (s[i] == ' ' && !x.empty()) 
        {
            if (!res.empty()) 
                res += ' '; 
            res += x;
            x.clear();
        }
    }

    // For the last word
    if (!x.empty()) {        
        if (!res.empty())
            res += ' ';
        res += x;
    }

    return res;
}