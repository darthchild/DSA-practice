/*
REDUCE THE GIVEN ARRAY 

Replace all the elements of the array with the index
it would have if the array was sorted 

{ 15, 10, 25, 20 }  ->  { 1, 0, 3 , 2 }

Basically, replace each element with the index it'll be at 
if the Array was to be sorted

*/


#include <bits/stdc++.h>
using namespace std; 

bool onCompare(pair<int,int> p1, pair<int,int> p2){
    return p1.first < p2.first;
}


int main(){

    vector<int> arr = {15,10,25,20};
    int len = arr.size();

    vector<pair<int,int>> v;

    // makes a vector of pairs, each E is a pair 
    // of the org array E & it's org index in the array
    // { (15,0) , (10,1) , (25,2) , (20,3) }
    for(int i=0; i < arr.size(); i++){
        v.push_back( make_pair(arr[i], i) );
    }

    sort(v.begin(), v.end(), onCompare);

    // now the vector is ->
    // { (10,1) , (15,0) , (20,3) , (25,2) }
    // we have to place 0 at IND-1, 1 at IND-0 & so on..

    for(int i=0; i < v.size(); i++){
        arr[ v[i].second ] = i;
    }

    // Printing the Output
    for(auto i: arr){
        cout << i << " ";
    }

}