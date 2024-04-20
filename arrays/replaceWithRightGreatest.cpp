/*
1299. Replace Elements with Greatest Element on Right Side

Given an array arr, replace every element in that array with 
the greatest element among the elements to its right, and 
replace the last element with -1.

After doing so, return the array.

Example 1:

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> replaceElements(vector<int>& a) {
        
    int n = a.size();
    int maxm = a[n-1];

    for(int i=n-2; i>=0; i--){

        int num = a[i];
        a[i] = maxm;

        maxm = max(num,maxm);
    }

    a[n-1] = -1;
    return a;
}


int main(){
    vector<int> arr = {17,18,5,4,6,1};
    replaceElements(arr);

    for(auto i:arr)
        cout << i << " ";
    cout << endl;
}