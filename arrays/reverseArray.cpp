/*
344. Reverse string (Leetcode)

Write a function that reverses a string. The input 
string is given as an Array of chars  s.
*/

#include <bits/stdc++.h>
using namespace std;

void swap(char &a, char &b){
    char temp = a;
    a = b;
    b = temp;
}

void reverseString(vector<char>& s) {
    
    int len = s.size();

    for(int i=0; i<(len/2); i++){
        swap(s[i],s[len-1-i]);
    }
}

int main(){
    vector<char> s = {'a','b','c','d'};
    reverseString(s);
	
    for(auto i:s)
         cout<<i;
}



