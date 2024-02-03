#include <bits/stdc++.h>
using namespace std;


// INITIAL APPROACH
// TC - O(n logn)
int missingNumber0(vector<int>& arr){


    int n = arr.size();
    sort(arr.begin(), arr.end());

    for(int i=0; i<n; i++){
        if(arr[i] != i){
            return i;
        }
    }
    return n;        
}

// BETTER SOLUTION
// TC - O(n)
int missingNumber(vector<int>& arr) {
    
    //  n = org Array.size - 1
    // we'll calc sum of first N-1 numbers
    // (N = size of org array)
    int n = arr.size();

    int orgSum = (n * (n+1) ) / 2;
    int currSum = 0;

    for(auto i:arr){
        currSum += i;
    }

    return orgSum - currSum;
    
}

int main(){


}