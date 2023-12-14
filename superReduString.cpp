// SUPER REDUCED STRING

/*
s = "abccba"

pattern found at index -> i=3  (i initialized at 1)

possibility of finding newly created pattern
at index (after erasing)-> i=2

relnship bw teh two index -> 3 "-1" = 2

thats why we decrement after every erase op, in 
order to find possibility of newly created pattern 
(as a result of erasing)


In: abbc
Out: ac

In: abba
Out: Empty String

In: abccba
Out: Empty String

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    
    int i = 1;
    while(i < s.size()){

        if(s[i-1] == s[i]){
            s.erase(i-1, 2);
            // we dont want to decrement i if its = to 1
            if( i != 1){  
                i--;
            }
        // if no match match found, just move ahead
        }else{
          i++;  
        } 
    }
    if(s == "") 
        s = "Empty String";
    
    cout << s;
    return 0;
}

