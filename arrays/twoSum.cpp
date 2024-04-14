/*
Given an array of integers arr and an integer target, return 
indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, 
and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: arr = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because arr[0] + arr[1] == 9, we return [0, 1].
*/


#include <bits/stdc++.h>
using namespace std;


// HASH MAP - ONE PASS

vector<int> twoSum(vector<int>& arr, int target) {
    unordered_map<int, int> numMap;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        int rem = target - arr[i];
        if (numMap.count(rem)) {
            return {numMap[rem], i};
        }
        numMap[arr[i]] = i;
    }

    return {}; // No solution found
}


// HASH MAP - TWO PASS (MINE)
vector<int> twoSum(vector<int>& arr, int target) {
    
    vector<int> ret;
    map<int,int> map;
    int n = arr.size();

    for(int i=0; i<n; i++){
        map[arr[i]] = i;
    }

    for(int i=0; i<n; i++){
        if(ret.size() == 2) break;
        int rem = target-arr[i];

        if(map.count(rem) && i != map[rem]){
            ret.push_back(i);
            ret.push_back(map[rem]);
        }  
    }
    return ret;
}
