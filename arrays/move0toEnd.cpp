/*
283. Move Zeroes
(Easy)
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 
Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
*/


#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}


// MY SOLUTION
void moveZeroes(vector<int>& a) {
    
    int i = -1;  // non-zero pointer
    int j = -1;  // zero pointer 
    int n = a.size();

    for(int k=0; k<n; k++){
        if(a[k] == 0){
            j = k;
            break;
        }        
    }
    
    if(j != -1)
        i = j+1;

    while(i > j && i < n){
        while(a[i] == 0 && i < n-1)
            i++;
        while(a[j] != 0)
            j++;
        if(i>j){
            swap(a[i],a[j]);    
            i++; j++;
        }
    }
}

// BETTER CODE 
void moveZeroesAgain(vector<int>& a){
    
    int j = -1;
    int n = a.size();

    for(int k=0; k<n; k++){
        if(a[k] == 0){
            j = k;
            break;
        }
    }

    // runs only if there are 0s present in the array
    if(j != -1){  
        for(int i = j+1; i<n; i++){
            if(a[i] != 0){
                swap(a[i],a[j]);
                j++;
            }
        }
    }
}


void printA(vector<int> arr){
    for(int i:arr)
        cout << i << " ";
    cout << endl;
}

void runCase(vector<int> a){
    moveZeroesAgain(a);
    printA(a);
}

int main(){

    runCase( {1,2,0,8,5,0,0,8,9} );
    runCase( {0} );
    runCase( {0,0} );
    runCase( {1,2} );
    runCase( {0,1,0} );
}