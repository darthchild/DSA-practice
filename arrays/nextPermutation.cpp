/*
31. Next Permutation
The next permutation of an array of integers is the next 
lexicographically greater permutation of its integer

For example, for arr = [1,2,3], the following are all the 
permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.
*/


#include <bits/stdc++.h>
using namespace std;


void nextPermutation(vector<int>& a) {
    
    int n = a.size();
    int ind = -1;

    // STEP-1: finding breakpoint (ind)
    // (that'll be 1st occ of a[i] < a[i+1] from arr's last 
    for(int i=n-2; i>=0; i--){
        if(a[i] < a[i+1]){
            ind = i;
            break;
        }
    }

    // STEP-2: if no BP found, given arr is the greatest/last perm
    // so the next Perm will the smallest/first one 
    if(ind == -1){
        reverse(a.begin(), a.end());
        return;
    }

    // STEP-3: Find num "just" greater than ind
    // among E to ind's right (which'll be the 1st E > ind from last of arr)
    for(int i=n-1; i>ind; i--){
        if(a[i] > a[ind]){
            swap(a[i],a[ind]);
            break;
        }
    }

    // STEP-4: Reverse E after "ind" index 
    // (they need to the smallest possibel combi, to make this perm the Lexo next one)
    reverse(a.begin()+ind+1, a.end());
}

int main(){
    vector<int> arr = {1,2,3,4};
    nextPermutation(arr);

    for(int i:arr)
        cout << i << " ";
        
}