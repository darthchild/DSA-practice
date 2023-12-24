#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> A = {2,6,5,4,7,2};

    int temp = A[0];

    for(int i=0; i<A.size()-1; i++){
        A[i] = A[i+1];
    }

    A[A.size()-1] = temp;

    for(int i:A)
        cout << i << " ";
}