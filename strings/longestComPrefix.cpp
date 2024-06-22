#include <bits/stdc++.h>
using namespace std;


// SOLUTION #1
// TC: O(n*m) SC: O(1), m-> size of arr's shortest string 
int match(string s1, string s2){
    int n = s1.size(), m = s2.size(),i = 0, j = 0;

    while(i<n && j<m){
        if(s1[i] == s2[j]){
            if(i < n) i++; 
            if(j < m) j++;
        } else
            break;
    }
    return i;
}

string longestCommonPrefix(vector<string>& a) {
    
    int maxLen = INT_MAX, n = a.size();
    if(n == 1) return a[0];

    for(int i=0; i<n-1; i++){
        if(a[i].empty() || a[i+1].empty())
            return "";
        else 
            maxLen = min(maxLen,match(a[i],a[i+1]));
    }

    return a[0].substr(0,maxLen);
}


// SOLUTION #2
// TC: O(n*m) SC: O(m), m-> size of arr's 1st string
string longestCommonPrefix1(vector<string>& a) {
    if (a.empty()) return "";

    string p = a[0];
    int pl = p.length();

    for (int i = 1; i < a.size(); i++) {
        string s = a[i];
        while (pl > s.length() || p != s.substr(0, pl)) {
            pl--;
            p = p.substr(0, pl);
            if (pl == 0) return "";
        }
    }
    return p;        
}


int main(){

    vector<string> a = { "flower","flow","flight" };
    cout << longestCommonPrefix1(a) << endl;
    
}


// IMP TEST CASES (input array a)
// "flower","flow","flight"
// "dog","racecar","car"
// "aya",""
// "lol"
// ""
// "",""
// "yolo","yo",""
