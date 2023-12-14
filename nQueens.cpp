#include <iostream>
#include <string>
using namespace std;

bool isSafe(int k, int i){

    for(int j=1; j<k; j++){
        if(x[j] == i || abs(x[j]-1) == abs(j-k)){
            return false;
        }
    }
    return true;
}

void displayArray(int arr[]){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i];
        
    }
}

void Nqueens(int k, int n){
    for(int i=0; i<arr.; i++){
        if(isSafe(k,i)){
            x[k] = i;
            if(k == n){
                displayArray(x,n);
            } else {
                Nqueens(k+1,n);
            }
        }
}

int main(){
    Nqueens(0,4);
    int x[4];
}