/*
451. Sort Characters By Frequency
Medium
Given a string s, sort it in decreasing order based on the frequency of
the characters. The frequency of a character is the number of times it appears in the string.
Return the sorted string. If there are multiple answers, return any of them.


Example 1:
Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
*/

static bool onCompare(pair<char,int> a, pair<char,int> b){
    return a.second > b.second;
}

string frequencySort(string s) {
    
    vector<pair<char,int>> map;
    for(char c:s){
        bool found = false;
        // searching for the char in the vec map
        for(auto& p:map){
            if(p.first == c){
                p.second ++;
                found = true; 
                break;
            }
        }
        // if not found, we create that char's pair with Freq = 1
        if(!found)
            map.push_back({c,1});
    }

    sort(map.begin(),map.end(),onCompare);

    string res;
    for(auto p : map) {
        res.append(p.second, p.first);
    }

    return res;

}