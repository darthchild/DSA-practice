// FIND THE SECOND LARGEST ELEMENT IN THE ARRAY 

#include <bits/stdc++.h> 
using namespace std;

int seclargestElement(vector<int> &arr, int n) {
    // Write your code here.

    int max;

    for(int i=0; i<n; i++){
       max = arr[i];
       for(int j=0; j<n; j++){
           if(arr[j] > max){
               max = arr[j];
           }
       } 
    }

    int secMax = 0;
    for (int i = 0; i < n; i++)
    {
        int diff = max - arr[i];

        if( diff < max - secMax && diff != 0){
            secMax = arr[i];
        }
    }
    
    cout << secMax<< "\n";
    cout << max<< "\n";
    
}

int main(){
    vector<int> arr = {3,9,4,12,8,10,6,5};
    largestElement(arr,arr.size());

}
