#include <bits/stdc++.h>
using namespace std;


vector<string> readLogs(vector<string> logs, int T){

    int pos1,pos2;
    string first, second;
    unordered_map<string,int> map;
    vector<string> res;

    for(string s:logs){

        pos1 = s.find(' ');
        first = s.substr(0,pos1);

        pos2 = s.find(' ', pos1+1);
        second = s.substr(pos1+1, pos2-pos1-1);

        map[first]++;
        if(first != second) map[second]++;

    }

    for(auto p:map){
        if(p.second >= T)
            res.push_back(p.first);
    }

    sort(res.begin(),res.end());
    return res;

}

void runTestCase(vector<string> logs, int T, vector<string> answer){

    vector<string> res = readLogs(logs,T);

    cout << endl << "Expected Output: " << endl;
    for(auto i:answer)
        cout << i << " ";

    cout << endl << "Your Output: " << endl;
    for(auto i:res)
        cout << i << " ";
    cout << endl;

}

int main(){
    
    runTestCase(
        {"88 99 2", "88 99 3", "99 32 1", "12 12 15"},
        2,
        {"88","99"}
    );


    runTestCase(
        {"9 7 50", "22 7 20", "33 7 50", "22 7 30"},
        3,
        {"7"}
    );

    runTestCase(
        {"1 2 5", "1 7 7", "1 3 2", "2 2 7"},
        2,
        {"1","2"}
    );

}