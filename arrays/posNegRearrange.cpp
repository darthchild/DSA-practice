#include <bits/stdc++.h>
using namespace std;


vector<int> rearrangeArray(vector<int>& arr) {
    
    vector<int> pos;
    vector<int> neg;
    
    for(int i:arr){
        if(i>0)
            pos.push_back(i);
        else
            neg.push_back(i);
    }

    vector<int> res;

    for(int i = 0 ; i < pos.size(); i++){
        res.push_back(pos[i]);
        res.push_back(neg[i]);
    }

    return res;
}


vector<int> rearrangeArray1(vector<int>& arr) {
    vector<int> res(arr.size());
    int posIdx = 0, negIdx = 1;

    for (int num : arr) {
        if (num > 0) {
            res[posIdx] = num;
            posIdx += 2;
        } else {
            res[negIdx] = num;
            negIdx += 2;
        }
    }

    return res;
}


int main(){

    vector<int> arr = {-3,-2,1,2,3,-1};
    vector<int> res = rearrangeArray1(arr);

    for(int i:res)
        cout << i << " ";
}