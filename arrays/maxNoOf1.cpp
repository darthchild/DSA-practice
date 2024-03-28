#include <bits/stdc++.h>
using namespace std;


int findMaxConsecutiveOnes(vector<int>& arr) {
    
    int n = arr.size();
    int cnt = 0;
    int max = 0;

    for(int i=0; i<n; i++){
        if(arr[i] == 1){
            cnt++;
            if(cnt > max)
                max = cnt;
        } else {
            cnt = 0;
        }
    }

    return max;
}
