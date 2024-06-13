/*
697. Degree of an Array
(Easy)
Given a array of positive integers nums, the degree of this array
is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, 
that has the same degree as nums.

Example 1:

Input:  [1,2,2,3,2,1,3]
Output: 4
Explanation: 
    The input array has a degree of 3 because the element 2 appear thrice.
    Of the subarrays that have the same degree:
    [1,2,2,3,1] [2,2,3,2] [2,2,3,2,1] etc
    The shortest length is 4. So return 4.
*/


#include <bits/stdc++.h>
using namespace std;


// Finding the length of Subarray for a particular 
// Most Freq. E (SA with deg = deg of Array)
int findDistance(int e, vector<int>& arr){
    
    // we'll find dist by calc. the diff bw 1st & 
    // last occurence of the Most Freq. element)
    int n = arr.size();
    int i = 0, j = n - 1;

    while (i <= j) {
        if (arr[i] != e)
            i++;
        if (arr[j] != e) 
            j--;
        if(arr[i] == e && arr[j] == e)
            break;
    }
    return j-i+1;
}


int findShortestSubArray(vector<int>& arr) {
    
    unordered_map<int,int> map; // hash map
    int deg = 0;

    for(int& i:arr){
        map[i]++;
        deg = max(deg,map[i]);
    }

    vector<int> list; // list of all elements with freq = Max freq (degree)
    for(auto& p:map){
        if(p.second == deg)
            list.push_back(p.first);
    }

    // finding which Most Freq. E's subarray length is least
    int ans = INT_MAX;
    for(int& e:list)
        ans = min(ans,findDistance(e,arr));

    return ans;
}

// we've used "&" in the loops here for better efficiency 
// as then, unecessary copies wont be created

int main(){
    vector<int> arr = {1,2,2,3,2,1,3};
    cout << findShortestSubArray(arr);
}