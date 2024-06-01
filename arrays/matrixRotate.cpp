/*

48. Rotate Image

You are given an n x n 2D matrix representing an image, 
rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to 
modify the input 2D matrix directly. DO NOT allocate another 2D 
matrix and do the rotation.

Input:  [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

*/


#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& mat) {
    
    int n = mat.size();

    // Step 1: find transpose of matrix
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Step 2: reverse the individual rows 
    for(auto& arr:mat){     
        int i = 0, j = n-1;
        
        while(i != j && i < j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
}


int main(){

    vector<vector<int>> mat = { {1,2,3}, {4,5,6}, {7,8,9} };
    rotate(mat);

    for(auto a:mat){
        for(auto i:a){
            cout << i << " ";
        }
    }
}