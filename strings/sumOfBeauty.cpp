class Solution {
public:
/*
1781. Sum of Beauty of All Substrings
Medium
The beauty of a string is the difference in frequencies between the most frequent
and least frequent characters.

For example, the beauty of "abaacc" is 3 - 1 = 2.
Given a string s, return the sum of beauty of all of its substrings.

Example 1:
Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"],
each with beauty equal to 1.
*/

int beauty(vector<int> &f) {
    int mf = INT_MIN, lf = INT_MAX;
    
    for(int i = 0; i < 26; i++) {
        if(f[i] > 0) {
            if(f[i] > mf)  mf = f[i];
            if(f[i] < lf)  lf = f[i];
        }
    }
    return mf - lf;
}

int beautySum(string &s) {
    
    int n = s.length(), res = 0;
    
    for(int i = 0; i < n; i++) {
        vector<int> f(26, 0);

        for(int j = i; j < n; j++) {
            f[s[j] - 'a']++;
            if(j-i >=2) 
                res += beauty(f);
        }
    }
    
    return res;
}