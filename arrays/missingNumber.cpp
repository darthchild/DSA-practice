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

    int n = arr.size()+1;

    int orgSum = ( (n-1) * (n) ) / 2;
    int currSum = 0;

    for(auto i:arr){
        currSum += i;
    }

    return orgSum - currSum;
    
}

int main(){


}