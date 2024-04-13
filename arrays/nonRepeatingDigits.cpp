/*

Given two positive integers, give the count of all numbers between them 
(both inclusive) which dont have any repeating digits

Examples - 

Input: 10 15
Output: 10 12 13 14 15  
(11 not included sue to repeating 1)

Input : 1 100
Output : 90






https://www.tutorialspoint.com/total-numbers-with-no-repeated-digits-in-a-range







Question: Given a range of integers determine how many numbers have no repeating digits

Solution:
Assumption: (General case): Range of integers are usually provided to be integer a < 10 power k
For example :
0 to 99 be expressed as integer a < 10 power 2
0 to 999 will be expressed as integer a < 10 power 3

The required number of integers for range 0 to "1 less than 10 power k" i.e. [0, 10 power k) = P (10,k)
NOTE: Here P(n,k) means the k-permutation of n.

0 to 9: P(10,1) = 10 is the answer
00 to 99: P(10,2) = 90 is the answer
00 to 999: P(10,3) = 720 is the answer.

The solution does not necessarily need to be written as source code, because I assume this is a interview question targeting your math.

*/