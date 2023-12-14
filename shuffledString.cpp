#include <bits/stdc++.h>
using namespace std;

/*
You are given a string s and an integer array indices
of the same length. The string s will be shuffled such
that the character at the ith position moves to indices[i]
in the shuffled string.

Return the shuffled string.
*/

string restoreString(string s, vector<int>& indices) {
    string answer;
    answer.resize(s.length());
    // here we need to set the length of the string first 
    // before assigning chars to it by indices 

    for(int i=0; i < s.length(); i++){
        answer[indices[i]] = s[i];
    }
   
    return answer;
}


int main(){
    return 0;
}
