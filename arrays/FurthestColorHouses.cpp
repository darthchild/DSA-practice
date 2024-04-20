/*
2078. Two Furthest Houses With Different a

There are n houses evenly lined up on the street, and each house is painted.
You are given a 0-indexed integer array a of length n, where a[i]
represents the color of the ith house.

Return the maximum distance between two houses with different a.

                 '     '
Input: a = [1,1,1,6,1,1,1]
Output: 3

                 '       '
Input: a = [1,8,3,8,3]
Output: 4
*/

#include <bits/stdc++.h>
using namespace std;



// MY SOLUTION - O(n) 
int maxDistance(vector<int>& a) {

    int i = 0, j = a.size()-1;
    int maxDist = 0;

    while(i != j){
            
        if(a[i] != a[j] && j != i){
            maxDist = max(maxDist,abs(i-j));
        }

        j--;
        if(i == j){
            i++;
            j = a.size()-1;
        }
    }
    return maxDist;
}


// One pass O(n) solution 
int maxDistance1(vector<int>& a) {

    int n = a.size();
    int max1 = 0,max2 = 0;
    int paint1 = a[0], paint2 = a[n-1];
    int start1 = 0, start2 = n-1;

    for(int i=1; i<n; i++){
        if(a[i]!=paint1) 
            max1 = max(max1,abs(i-start1));

        if(a[n-i-1]!=paint2) 
        max2 = max(max2,abs(n-i-1-start2));
    }
    return max(max1,max2);

}

int main(){
    vector<int> arr = {1,8,3,8,3};
    cout << maxDistance1(arr);
}
