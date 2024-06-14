#include <bits/stdc++.h>
using namespace std;


/*
509. Fibonacci Number
The Fibonacci numbers, commonly denoted F(n) form a sequence, 
called the Fibonacci sequence, such that each number is the sum of 
the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

Example 1:
    Input: n = 2
    Output: 1
    Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
*/

// Using Top-Down DP or Memoization
// TC - O(n), SC - O(n)
int dp[31] = {0};

int fib(int n){
    
    if(n <= 1) return n;
    if(dp[n] > 0) return dp[n];

    dp[n] = fib(n-1) + fib(n-2);
    return dp[n];
}

// Naive Recursive Soln
// TC - O(2^n), SC - O(n)

int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}




bool isPalindrome(int num) {
        
    if(num < 0)
        return 0;

    long rev = 0, x = num;
    while(x > 0){
        int dig = x % 10;
        x = x / 10;
        rev = (rev*10) + dig;
    }

    if(rev == num)
        return true;
    return 0;
}


/*
7. Reverse Integer
Given a signed 32-bit integer x, return x with its digits reversed.
If reversing x causes the value to go outside the signed 32-bit integer 
range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers
(signed or unsigned).

Example 1:
    Input: x = 123
    Output: 321

Example 2:
    Input: x = -123
    Output: -321
*/

int reverse(int num) {

    long rev = 0;

    while(num){
        int dig = num % 10;
        num = num/10;
        rev = (rev*10) + dig;
    }
    
    if(rev > INT_MAX || rev <= INT_MIN)
        return 0;

    return rev;    
}