#include <bits/stdc++.h>
using namespace std;

/*
0. Sum of elements in a matrix
Given a non null integer matrix Grid of dimensions NxM.
Calculate the sum of its elements.
(This can't be done in less than O(n^2) time
*/

int sumOfMatrix(int N, int M, vector<vector<int>> mat) {
    
    int sum = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            sum += mat[i][j];
        }
    }
    
    return sum;   
}

/*
1. Find difference between sum of diagonals
Given a matrix Grid[][] of size NxN. Calculate the absolute 
difference between the sums of its diagonals.
*/

int diagonalSumDifference(int N, vector<vector<int>> mat) {
    int sum1 =0, sum2 = 0;
    int n = mat.size();
    
    //left diagonal, condition -> i == j
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j)
                sum1 += mat[i][j];
        }
    }
    
    //right diagonal, condition -> i+j == n-1
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i+j == n-1)
                sum2 += mat[i][j];
        }
    }
    
    return abs(sum2-sum1);
}

/*
2. Transpose of Matrix
Write a program to find the transpose of a square matrix of size N*N. 
Transpose of a matrix is obtained by changing rows to columns and 
columns to rows.
*/

void transpose(vector<vector<int>>& mat, int n)
{ 
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            swap(mat[i][j], mat[j][i]);
        }
    }


    // OR 

    // this one does one less swap (which was extra in the first one)
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            swap(mat[i][j], mat[j][i]);
        }
    }
}


/*

Rotate by 90 degree
Given a square matrix of size N x N. The task is to rotate it by 90 degrees 
in anti-clockwise direction without using any extra space
*/

// For Anti-Clockwise rotatuion - 1st reverse rows, 2nd transpose
// For Clockwise rotatuion - 1st transpose, 2nd reverse rows


void rotateby90(vector<vector<int>>& mat, int n) 
{ 
    // Step-1: reverse rows
    for(auto& a:mat){
        int i=0;
        int j = a.size()-1;
        while(i<j && i != j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    
    
    //Step-2:transpose
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            swap(mat[i][j], mat[j][i]);
        }
    }
    
} 
