#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& a) {
        
    // Map <Num,frequency>
    map<int,int> pairs;

    for(int i=0; i<a.size(); i++){
        
        if(pairs.find(a[i]) != pairs.end())
            pairs[a[i]]++;

        if(pairs.find(a[i]) == pairs.end())
            pairs[a[i]] = 1;
    }

    // finding the Num with frequency = n/2
    int n = a.size() / 2;

    for(auto it:pairs){
        if(it.second > n)  
            return it.first;
    }

    return 0;
}

// O(1) space algo
/*
Intuition of the approach: 
if an element occurs more than n/2 times in the array,
it will always occupy the middle position when the array 
is sorted. Therefore, we can sort the array and return 
the element at index n/2.
*/

int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    return nums[n/2];
}

int main(){
    vector<int> arr = {};
    cout << majorityElement(arr);
}