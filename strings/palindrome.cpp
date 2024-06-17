/*
125. Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into 
lowercase letters and removing all non-alphanumeric characters, it reads
the same forward and backward. Alphanumeric characters include letters 
and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
    Input: s = "A man, a plan, a canal: Panama"
    Output: true
    Explanation: "amanaplanacanalpanama" is a palindrome.
*/

#include <bits/stdc++.h>
using namespace std;


// using O(n) space
bool isPalindrome(string s) {
    
    string filtd; // for the filtered string
    for (char& c : s) {
        if (isalnum(c)) 
            filtd += tolower(c);
    }

    string rev = filtd;
    if(!rev.empty()){
        reverse(rev.begin(),rev.end());
        return filtd == rev;
    }
    return 1; // empty string is a palinddrome
        
}


// using O(1) space
bool isPalindrome1(string s) {

    int i = 0, j = s.size()-1;

    while(i <= j){
        while(!isalnum(s[i]) && i<j)
            i++;
        while(!isalnum(s[j]) && j>i)
            j--;

        if(tolower(s[i]) != tolower(s[j])){
            return false;
        } else { 
            i++; j--;
        }
    }
    return true;
}

int main(){
    string s = "A man, a plan, a canal: Panama";
    cout << isPalindrome1(s);

}