/*
349. Intersection of Two arrays

Given two integer arrays nums1 and nums2, return 
an array of their intersection. Each element in the result 
must be unique and you may return the result in any order.

 
Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
([4,9] is also accepted.)
*/

#include <bits/stdc++.h>
using namespace std;


vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

    vector<int> inter;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int n1 = nums1.size();
    int n2 = nums2.size();
    int i = 0, j = 0;

    while (i < n1 && j < n2) {
        if (nums1[i] < nums2[j]) {
            i++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            // Found an intersection element
            inter.push_back(nums1[i]);
            i++;
            j++;
            
            // Double check for duplicates
            while (i < n1 && nums1[i] == nums1[i - 1]) {
                i++;
            }  
            while (j < n2 && nums2[j] == nums2[j - 1]) {
                j++;
            }
        }
    }

    return inter;
}

int main(){

    vector<int> nums1 = {6,1,2,3,1,2};
    vector<int> nums2 = {2,2,1,6};

    vector<int> ans = intersection(nums1,nums2);

    for(auto i:ans)
        cout << i << " ";
}
