/*

Given two positive integers, give the count of all numbers between them 
(both inclusive) which dont have any repeating digits

Examples - 

Input: 10 15
Output: 10 12 13 14 15  
(11 not included due to repeating 1)

Input : 1 100
Output : 90
*/

#include <bits/stdc++.h>
using namespace std;


// 1. BRUTE FORCE , TC: O(n*k) 
//      k = max no. of digits in a number
//      n = total no. of nums bw the given numbers
int method1(int lower, int upper){

    int answer = upper-lower+1;
    int flag = 0;
    
    for(int i=lower; i <= upper; i++){
        int cnt = 0;
        string s = to_string(i);
        
        for(int j=0; j<s.length(); j++){
            flag = 0;
            cnt = count(s.begin(),s.end(),s[j]);
            
            if(cnt > 1){
                flag = 1;
                break;
            }
        }
        
        if(flag ==1) answer --;
    }

    return answer;
}


int main() {
    
    // INPUTS:
    int lb = 0;
    int ub = 99;

    cout << method1(lb,ub);
    
    
    return 0;
    
}