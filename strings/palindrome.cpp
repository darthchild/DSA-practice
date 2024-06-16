#include <bits/stdc++.h>
using namespace std;


// using O(n) space
bool isPalindrome(string s) {
    
    string filt;
    for (char& c : s) {
        if (isalnum(c)) 
            filt += tolower(c);
    }

    string org = filt;
    if(!filt.empty()){
        reverse(filt.begin(),filt.end());
        return filt == org;
    }
    return 1;
        
}


// using O(1) space
bool isPalindrome1(string s) {
    int start = 0;
    int end = s.size() - 1;

    while(start<=end){

        if(!isalnum(s[start])){
            start++; 
            continue;
        }
        if(!isalnum(s[end])){
            end--;
            continue;
        }

        if(tolower(s[start]) != tolower(s[end])){
            return false;
        } else {
            start++;
            end--;
        }
    }
    return true;
}

int main(){

}