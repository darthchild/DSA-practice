/*

FREQUENCY COUNT OF EACH ELEMENT

Determine the frequency count of each element within a given array.
Write a code to find the frequency count of each element.

  Example:
-> If you are giving input 1 3 2 4 5 4
-> Step 1 : Arrange the elements in ascending order - 1 2 3 4 4 5
-> The frequency of given number 0-0, 1-1, 2-1, 3-1, 4-2, 5-1
-> So the output is 0 1 1 1 2 1

  Exercise-1
input:
8
1 3 4 5 4 3 6 2
output:
0 1 1 2 2 1 1

  Exercise-2
input:
6
7 3 8 5 7 3
output:
0 0 0 2 0 1 0 2 1
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

	vector<int> arr;
	vector < pair<int,int> > v; 
	
	cout << "input length : ";
	int len; 
	cin >> len; 

	cout << "input array : ";
	for (int i = 0; i < len; i++){
		int x;
        cin >> x;
        arr.push_back(x);
	}

	sort( arr.begin(), arr.end() );
	int largest = arr[len - 1];

	for (int i = 0; i <= largest; i++){
		int c = count(begin(arr), end(arr), i);
		v.push_back(make_pair( i, c ));
	}

	for( auto i: v){
	    cout << i.second <<" ";
	}
}
