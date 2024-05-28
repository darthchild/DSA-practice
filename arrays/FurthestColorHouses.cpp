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



// MY SOLUTION - O(n^2) 
int maxDistance(vector<int>& a) {

    int maxDist = 0;
    int n = a.size();

    for(int i=0; i < n; i++){
        for(int j=i+1; j < n; j++){
            if(a[i] != a[j])
                maxDist = max(maxDist, abs(j-i));
        }
    }
    return maxDist;
}


// One pass O(n) solution 
int maxDistance1(vector<int>& a) {

    int n = a.size();
    int max1 = 0,max2 = 0;
    int start = a[0], end = a[n-1];

    for(int i=1; i<n; i++){
        if(a[i] != start) 
            max1 = max(max1,i);

        int j = n-i-1;
        
        if(a[j] != end) 
            max2 = max(max2, abs(j-(n-1)) );
    }
    return max(max1,max2);

}

int main(){
    vector<int> arr = {1,8,3,8,3};
    cout << maxDistance1(arr);
}
