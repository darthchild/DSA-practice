#include <bits/stdc++.h>
using namespace std;
#define PB push_back


void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; 
    int l = low;      // iterator for left half of arr
    int r = mid + 1;  // iterator for right half of arr

    // storing elements in the temp arr in a sorted manner
    while (l <= mid && r <= high) {
        if (arr[l] <= arr[r]) {
            temp.PB(arr[l]);
            l++;
        }
        else {
            temp.PB(arr[r]);
            r++;
        }
    }

    // For leftover Es in Left half
    for(int i=l; i<=mid; i++)
        temp.PB(arr[i]);

    // For leftover Es in Right half 
    for(int i=r; i<=high; i++)
        temp.PB(arr[i]);

    // copying all Es from temp to arr (now sorted)
    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}

void mergeSort(vector<int> &arr, int low, int high) {
    
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);  // sort left half
    mergeSort(arr, mid + 1, high); // sort right half
    
    merge(arr, low, mid, high);  // merge the sorted halves
}

int main() {

    vector<int> arr = {9, 4, 7, 6, 3, 1, 5}  ;
    int n = 7;

    mergeSort(arr, 0, n - 1);

    for(auto i:arr)
        cout << i << " ";
    cout << endl;
}