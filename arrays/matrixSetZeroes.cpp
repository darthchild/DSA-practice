/*
73. Set mat Zeroes
Medium
Given an m x n integer mat mat, if an element is 0, 
set its entire row and column to 0's. You must do it in place.

Example 1:
Input: mat = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: mat = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

*/
#include <bits/stdc++.h>
using namespace std;


// BRUTE FORCE 
void setZeroes(vector<vector<int>>& mat) {
    
    int n = mat.size(); //row
    int m = mat[0].size(); //col

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){

            if(mat[i][j] == 0){

                // setting whole i'th row as 0s
                for(int k=0; k<m; k++){
                    if(mat[i][k] != 0)
                        mat[i][k] = INT_MAX;
                }

                // setting all (x,j)th E as 0
                for(int k=0; k<n; k++){
                    for(int l=0; l<m; l++){
                        if(l==j && mat[k][l] != 0)
                            mat[k][l] = INT_MAX;
                    }
                }
            }     
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == INT_MAX)
                mat[i][j] = 0;
        }
    }  
}


// OPTIMAL
void setZeroes1(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    bool flag1 = false, flag2 = false;
    for(int i=0; i<n; i++){
        if(mat[i][0] == 0){
            flag1 = true;
        }
    }
    for(int j=0; j<m; j++){
        if(mat[0][j] == 0){
            flag2 = true;
        }
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(mat[i][j] == 0){
                mat[i][0] = mat[0][j] = 0;
            }
        }
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(mat[i][0] == 0 || mat[0][j] == 0){
                mat[i][j] = 0;
            }
        }
    }
    
    if(flag1 == true){
        for(int i=0; i<n; i++){
            mat[i][0] = 0;
        }
    }
    if(flag2 == true){
        for(int j=0; j<m; j++){
            mat[0][j] = 0;
        }
    }
}



int main() {
    
    vector<vector<int>> mat = {{1,2,3,0},{4,5,6,1},{8,0,1,2}};
    
    // original mat
    for(auto a:mat){
        for(auto i:a)
            cout << i << " ";
        cout << endl;
    }
    cout << endl;
    
    setZeroes1(mat);

    // after zeroing
    for(auto a:mat){
        for(auto i:a)
            cout << i << " ";
        cout << endl;
    }
}