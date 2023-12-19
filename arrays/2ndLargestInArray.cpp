
#include <bits/stdc++.h>

using namespace std;

void findSecMax(vector<int> arr){
	int max = arr[0];
	int secMax = 0;

	// finds largest element
	for(int i : arr){
		if(i > max)
			max = i;
	}

	// finds 2nd largest element
	for(int i : arr){
		if(max-i < max-secMax && i != max)
			secMax = i;
	}
	cout << max << " " << secMax << endl;
}


int main(){

	vector<int> arr = {-1,0,4,-3};
	findSecMax(arr);
	
}