/*
An array contains both positive and negative numbers in random order.
Rearrange the array elements so that all negative numbers appear
before all positive numbers.
*/

#include <bits/stdc++.h>
using namespace std;

void swap(int ind1, int ind2, vector<int> &vec)
{
    int x = vec[ind1];
    vec[ind1] = vec[ind2];
    vec[ind2] = x;
}

int main()
{
    vector<int> arr = {-6, -5, 3, 4, -1, 1, -2};

    int i = 0;
    int j = arr.size() - 1;

    while (j > i){
        while (arr[i] < 0)
            i++;
        while (arr[j] > 0)
            j--;
        if (j > i)
            swap(arr[i], arr[j]);
    }

    for (int num : arr){
        cout << num << " ";
    }
}
