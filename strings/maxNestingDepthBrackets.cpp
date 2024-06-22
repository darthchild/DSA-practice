/*
1614. Maximum Nesting Depth of the Parentheses
Easy
Given a valid parentheses string s, return the nesting depth of s.
The nesting depth is the maximum number of nested parentheses.

Example 1:
Input: s = "(1+(2*3)+((8)/4))+1"
Output: 3
Explanation:
Digit 8 is inside of 3 nested parentheses in the string.

Example 2:
Input: s = "(1)+((2))+(((3)))"
Output: 3
Explanation:
Digit 3 is inside of 3 nested parentheses in the string.

Example 3:
Input: s = "()(())((()()))"
Output: 3
*/

#include <bits/stdc++.h>
using namespace std;


int maxDepth(string str) {
    
    int maxD = 0, bal = 0;

    for(char c:str){
        if(c == '(')
            bal++;
        else if(c == ')')
            bal--;
        maxD = max(bal,maxD);
    }

    return maxD;
}
