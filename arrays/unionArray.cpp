/*
Union of Two Sorted Arrays
(Medium)
Given two sorted arrays of size n and m respectively, 
find their union. The Union of two arrays can be defined 
as the common and distinct elements in the two arrays. Return 
the elements in sorted order.

Example 1:
Input: 
    n = 5, arr1[] = {1, 2, 3, 4, 5}  
    m = 5, arr2 [] = {1, 2, 3, 6, 7}
Output: 
    1 2 3 4 5 6 7
Explanation: 
    Distinct elements including both the arrays are: 1 2 3 4 5 6 7.
*/



#include <bits/stdc++.h>
using namespace std;


// Brute Force
vector<int> unionOfArray(vector<int> a, vector<int> b){
    int n = a.size(), m = b.size();
    unordered_set<int> set;
    vector<int> res;
    
    for(int i=0; i<n; i++)
        set.insert(a[i]);
    
    for(int i=0; i<m; i++)
        set.insert(b[i]);
      
    for(auto it:set)
        res.push_back(static_cast<int>(it));
    
    sort(res.begin(),res.end());
    return res;
}


// Optimal 
vector<int> unionOfArray1(vector<int> a, vector<int> b){
    int n = a.size(), m = b.size(), i = 0, j = 0;
    vector<int> res;
    
    while( i<n && j<m){
        if(a[i] <= b[j]){
            if(res.size() == 0 || res.back() != a[i])
                res.push_back(a[i]);
            i++;
        } 
        else
        {
            if(res.size() == 0 || res.back() != b[j])
                res.push_back(b[j]);
            j++;
        
        }
    }

    while(i<n){
        if(res.size() == 0 || res.back() != a[i] )
            res.push_back(a[i]);
        i++;
    }
    while(j<m){
        if(res.size() == 0 || res.back() != b[j])
            res.push_back(b[j]);
        j++;
    }
    return res;
}


int main(){
    vector<int> arr1 = {1,1,2,3,4}, arr2 = {2,2,3,4,4,5};
    vector<int> res = unionOfArray1(arr1,arr2);

    for(int i:res)
        cout << i << " ";
    cout << endl;
        
}