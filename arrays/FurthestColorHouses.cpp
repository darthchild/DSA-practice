/*
2078. Two Furthest Houses With Different Colors

There are n houses evenly lined up on the street, and each house is painted.
You are given a 0-indexed integer array colors of length n, where colors[i]
represents the color of the ith house.

Return the maximum distance between two houses with different colors.

                 '     '
Input: colors = [1,1,1,6,1,1,1]
Output: 3

                 '       '
Input: colors = [1,8,3,8,3]
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

    int start = 0;
    int end = a.size() - 1;
    int hold = start, ret = 0;
    
    while(hold < a.size()){

        if(a[start] != a[hold]){
            int max1 = max(ret, hold - start);
            int max2 = max(ret, end - hold);
            ret = max(max1,max2);    
        }
        
        hold++;
    }
    return ret;
}

int main(){
    vector<int> arr = {1,8,3,8,3};
    cout << maxDistance1(arr);
}
