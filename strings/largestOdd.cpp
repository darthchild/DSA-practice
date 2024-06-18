/*
1903. Largest Odd Number in String
You are given a string num, representing a large integer. Return 
the largest-valued odd integer (as a string) that is a non-empty 
substring of num, or an empty string "" if no odd integer exists.

A substring is a contiguous sequence of characters within a string.


Example 1:
    Input: num = "402164"
    Output: "4021"

Example 2:
    Input: num = "206"
    Output: ""
    Explanation: There are no odd numbers in "206".
*/

#include <bits/stdc++.h>
using namespace std;


string largestOddNumber(string s) {
    
    int n = s.size(), last;

    for(int i=n-1; i>=0; i--){
        
        int dig = s[i] - '0';
        if(dig % 2 != 0){
            last = i;
            break;
        }      
    }

    string res = s.substr(0,last+1);
    return res;
}

    
// Brute Force Solution 
// con -> wont work for strings with length more than INT_MAX, 
// basically converting to int is not optimal as it 
// wont work for very large string inputs (as it will exceed size of int & long)

string largestOddNumber1(string s) {
    long maxNum = 0, n = s.size();
    string num = "";

    for(int i=n-1; i>=0; i--){

        int dig = s[i]-'0';
        cout << dig << endl;

        if(!num.empty() || dig % 2 != 0){
            num = s[i] + num;
            maxNum = max(stol(num),maxNum);
        } 
        
    }
    if(maxNum == 0)
        return "";
    else
        return to_string(maxNum);

    return res;
}