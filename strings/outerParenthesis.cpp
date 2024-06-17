/*
1021. Remove Outermost Parentheses

A valid parentheses string is either empty "", "(" + A + ")", 
or A + B, where A and B are valid parentheses strings, and + 
represents string concatenation.

For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not 
exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string s, consider its primitive decomposition: 
s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.

Return s after removing the outermost parentheses of every primitive string in 
the primitive decomposition of s.


Example 1:

Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".
*/


#include <bits/stdc++.h>
using namespace std;

// My solution 
string removeOuterParentheses(string s) {

    int first, op = 0, cl = 0;
    string res;

    for(int i=0; i<s.size();i++){
            
        if(s[i]== '('){
            if(op == 0) first = i;
            op ++;  
        } else {
            cl ++;
        }
        
        if(op == cl){
            res += s.substr(first+1, i-first-1);
            op=0, cl=0, first=0;
        }
    }
    return res;
    
}