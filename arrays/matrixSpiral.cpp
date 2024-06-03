/*
54. Spiral Matrix
Medium
Given an m x n matrix, return all elements of the matrix
in spiral order.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/


#include <bits/stdc++.h>
using namespace std;


// this problem has only 1 solution 
// (no diff brute force & optimal soln)

vector<int> spiralOrder(vector<vector<int>>& mat) {
    
    int n = mat.size(); //row
    int m = mat[0].size(); //col

    int left = 0, right = m-1, top = 0, btm = n-1;
    vector<int> res;

/*
        (L)   (R)
    (T)  1  2  3 
         4  5  6 
    (B)  7  8  9
*/

    while( top <= btm && left <= right){

        // left to right (1st row)
        for(int i=left; i<=right; i++)
            res.push_back(mat[top][i]);
        top ++;

        // top to bottom (last col)
        for(int i=top; i<=btm; i++)
            res.push_back(mat[i][right]);
        right --;

        // right to left (last row)
        if(top <= btm){
            for(int i=right; i>=left; i--)
                res.push_back(mat[btm][i]);
            btm --;
        }

        // bottom to top (1st col)
        if(left <= right){
            for(int i=btm; i>=top; i--)
                res.push_back(mat[i][left]);
            left ++;
        }
    }

    return res;
}


int main() {
    
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> result = spiralOrder(mat);

    // original matrix
    for(auto a:mat){
        for(auto i:a)
            cout << i << " ";
        cout << endl;
    }
    cout << endl;
    
    // spiral order
    for(auto i:result)
        cout << i << " ";
    cout << endl;
    
    return 0;
    
}