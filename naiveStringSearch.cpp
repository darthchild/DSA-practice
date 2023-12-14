/*
the function stringSearch() returns the index where the pattern
string is found inside the text string
*/


#include <iostream>
#include <string>
using namespace std;


void stringSearch(string txt, string pat){

    int n = txt.length();
    int m = pat.length();
    int i,j;

    for (i = 0; i < n-m+1; i++){
        for (j = 0; j < m; j++){
            if(txt[i+j] != pat[j]){
                break;
            }
        }
        if(j==m)
            cout << i << endl;
    }
}


int main(){
    stringSearch("abcdecd","cd");
}


